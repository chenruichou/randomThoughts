#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
	int jump(vector<int> &nums){
		int min_j = findMinJump(nums,0,0);
		return min_j;	
	}
	int findMinJump(vector<int> &nums, int indx, int num_jumps){
		// termination statement
		if(indx==nums.size()-1) return num_jumps;
		if(indx>nums.size()-1) return -1;
		
		int min_num_jumps = nums.size()+1; // set a max
		for(int i=1;i<=nums[indx];i++){
			int curr_num_jumps = findMinJump(nums, indx+i, num_jumps+1);
			if (curr_num_jumps != -1 && curr_num_jumps<min_num_jumps)
				min_num_jumps = curr_num_jumps;
		}
		if(min_num_jumps == nums.size()+1) // no legit paths found
			return -1;
		else
			return min_num_jumps;	
	}
};
int main(){
	Solution sol;
	vector<int> nums = {2,3,1,1,4};
	cout<<sol.jump(nums)<<endl;

	return 1;
}
