#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
       	if(nums.size()==0) return -1;
       	if(nums.size()==1) return nums[0]==target ? 0 : -1; 
    	int left = 0;
	int right = nums.size()-1;
	int mid = (left+right)/2;
       	while(left!=right){
		if(nums[left]==target) return left;
		if(nums[right]==target) return right;
		if(nums[mid]==target) return mid;
		if(target>nums[left] && target<nums[mid]){
			right = mid;
			mid = (left+right)/2;
		}else if(target>nums[mid] && target<nums[right]){
			left = mid;
			mid = (left+right)/2;
		}else if(nums[left]<nums[mid]){
			left = mid;
			mid = (mid+right)/2;	
		}else if(nums[mid]<nums[right]){
			right = mid;
			mid = (left+right)/2;
		}
	}
	return -1;
    }
};


int main(){
	Solution sol;
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	int out = sol.search(nums,1);
	cout << out << endl;
	return 1;
}
