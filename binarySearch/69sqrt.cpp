#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	int left=1;
	int right=x;
	while(left<right){
		cout << "("<<left<<","<<right<<")"<<endl; 
		long int target = (left+right)/2;
		long int target2 = target*target;
		if(target2==x){
			return target;
		}else if(target2<x){
			if(left==target) return target;
			left = target;
		}else{ //taret2>x
			if(right==target) return target;
			right = target;
		}
	}
	return left;    
    }
};

int main(){
	Solution sol;
	int out = sol.mySqrt(21473955);
	cout << out << endl;
	return 1;
}
