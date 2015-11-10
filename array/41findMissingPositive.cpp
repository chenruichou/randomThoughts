#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
	for(int i=0; i<nums.size();i++){
		if(nums[i]!=i) { // put 1 at index 0
			//SKIP for those out of bound or already correct
			if(nums[i] <= 0 || nums[i] >nums.size() || nums[i] == nums[nums[i] -1]) break;   
			//Index to swap to
			int indx=nums[i]-1;
			if(indx<0) indx=0;
			if(indx>nums.size()-1) indx=nums.size()-1;
			//Swap
			int temp = nums[i];
			nums[i] = nums[indx];
			nums[indx] = temp;
		}
	}
	//Scan again to detect the missing hole
	for(int i=0;i<nums.size();i++){
		if(nums[i]>0 && nums[i]!=i)
			return i;
	}
	return nums.size();
        
    }
};

int main(){
	Solution sol;
	vector<int> nums = {5,1,3,4,0};
	cout << sol.firstMissingPositive(nums)<< endl;

	return 1;
}
