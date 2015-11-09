#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
	for(int i=0; i<nums.size();i++){
		while(nums[i]!=i+1) { // put 1 at index 0
			//SKIP for those out of bound or already correct
			if(nums[i] <= 0 || nums[i] >nums.size() || nums[i] == nums[nums[i] -1]) break;   
			//SWAP
			int temp = nums[i];
			nums[i] = nums[nums[i]-1];
			nums[nums[i]-1] = temp;
		}
	}
	//Scan again to detect the missing hole
	for(int i=0;i<nums.size();i++){
		if(nums[i]!=i+1)
			return i+1;
	}
	return nums.size();
        
    }
};

int main(){
	Solution sol;
	vector<int> nums = {3,4,-1,1};
	cout << sol.firstMissingPositive(nums)<< endl;

	return 1;
}
