#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& v) {
    	int start=0;
	int end=v.size()-1;
	int curr_max = 0;
	while (start < end){
		int curr = min(v[start],v[end])*(end-start);
		if(curr>curr_max){
			curr_max = curr;
		}
		if(v[start]>v[end]){
			end -= 1;
		}else if(v[start]<v[end]){
			start += 1;
		}else{ // v[start]==v[end]
			start += 1;
		}
	}
	return curr_max;
    }
};


int main(){
	Solution sol;
	vector<int> v2 (3,5);
	vector<int> v = {1, 2, 13, 14, 5, 6};
	int out = sol.maxArea(v2);
	cout << out << endl;
	return 1;
}
