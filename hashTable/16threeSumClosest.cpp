#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
	int score = INT_MAX;
	int out = 0;
    	sort(nums.begin(),nums.end());
	for(auto it=nums.begin();it!=nums.end();it++){
		int first = *it;
		auto left = it+1;
		auto right = nums.end()-1;
		while(left<right){
			int curr_sum = *left+*right;
			if (curr_sum==target-first){
				return target;
			}else if(curr_sum < target-first){
				left++;
				int d = abs(target-curr_sum-first);
				if(d<score){
					score = d;
					out = curr_sum+first;
				}
			}else{
				right--;
				int d = abs(target-curr_sum-first);
				if(d<score){
					score = d;
					out = curr_sum+first;
				}
			}
		}
	}
	return out;    	
    }
};

int main(){
	Solution sol;
	vector<int> nums = {-1,2,1,-4};
	cout<<sol.threeSumClosest(nums,1)<<endl;
	return 1;
}
