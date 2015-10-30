#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> out;
	out.push_back(findLeftMost(nums,target));
	out.push_back(findRightMost(nums,target));
    	return out;
    }
    int findLeftMost(vector<int> &nums, int target){
	// binary search to find the left-most one
    	int out=-1;
	int left=0;
	int right=nums.size()-1;
	while(left<=right){
		int mid = (left+right)/2;
		if(nums[mid]>target){
			right = mid-1;
		}else if(nums[mid]<target){
			left = mid+1;
		}else{ // nums[mid]==target
			out = mid;
			right = mid-1;	
		}
	}
	return out;	
    }
    int findRightMost(vector<int> &nums, int target){
	// binary search to find the right-most one
	int out=-1;
	int left=0;
	int right=nums.size()-1;
	while(left<=right){
		int mid = (left+right)/2;
		if(nums[mid]>target){
			right = mid - 1;
		}else if(nums[mid]<target){
			left = mid + 1;
		}else{ // nums[mid]==target
			out = mid;
			left = mid + 1;
		}
	}
	return out;
    }

};


int main(){
	Solution sol;
	vector <int> nums = {5, 7, 7, 8, 8, 10};
	int target = 8;
	vector<int> out = sol.searchRange(nums,target);
	for(auto it=out.begin();it!=out.end();it++){
		cout << *it << " ";
	}
	cout << endl;
	return 1;
}
