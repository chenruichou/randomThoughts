#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	//vector<vector<int>> test(10,vector<int> (10,3));
	vector<vector<int>> out;
	sort(nums.begin(),nums.end());
	for(auto it=nums.begin();it!=nums.end();it++){
		//get the first number, and then search for the rest two by
		// the two-pointer method
		if(it>nums.begin() && *it==*(it-1))
			continue; // skip the repeated set
		int first = *it;
		int target = 0-*it;
		auto left = it+1;
		auto right = nums.end()-1;
		while(left<right){
			int curr_sum = *left+*right;
			if(curr_sum==target){
				vector<int> s;
				s.push_back(first);
				s.push_back(*left);
				s.push_back(*right);
				out.push_back(s);
				left++;
				right--;
			}else if(curr_sum<target){
				left++;
			}else{
				right--;
			}
		}
	}
	return out; 
    }
};

int main(){
	Solution sol;
	vector<vector<int>> out;
	vector<int> in = {1,2,-1,0,-4,-1};
	out = sol.threeSum(in);
	for(auto it=out.begin();it!=out.end();it++)
		cout<<"("<<(*it)[0]<<","<<(*it)[1]<<","<<(*it)[2]<<")"<<endl;
	return 1;
}
