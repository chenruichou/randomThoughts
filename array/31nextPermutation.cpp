#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	if(nums.size()<=1) return;
	int v=nums[nums.size()-1];
        for(auto it=nums.end()-2;it!=nums.begin()-1;it--){
		if(*it<v){
			int tmp = *it;
			*it = *(it+1);
			*(it+1) = tmp;
			return;
		}else{
			v = *it;
		}
	}

	// reverse vector
	int left=0;
	int right=nums.size()-1;
	while(left<right){
		int tmp = nums[left];
		nums[left]=nums[right];
		nums[right]=tmp;
		left++;
		right--;
	}
	return;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {9,9,3};
	sol.nextPermutation(nums);
	for(auto it=nums.begin();it!=nums.end();it++)
		cout<< *it << " ";
	cout<<endl; 
	return 1;
}
