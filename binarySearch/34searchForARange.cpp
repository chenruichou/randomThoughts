#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int left = 0;
	int right = nums.size()-1;
	int mid = (left+right)/2;
	vector<int> out (2,-1); // indice of left and right
	while(left<right){
		if(nums[left]==target){
			out[0] = left;
		}
		if(nums[right]==target){
			out[1] = right;
		}
		if(nums[mid]==target)
		if(out[0]!=-1 && out[1]!=-1) return out;
		
		
	}   
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
