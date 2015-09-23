#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       	if(nums.size()==0) return 0;
	int end=0;
	for(int i=1;i<nums.size();i++){
		if(nums[end]!=nums[i]){
			end++;
			nums[end]=nums[i];
		}	
       	} 
	return end+1;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1,1,3,3,3,5,7,8};
	int n = sol.removeDuplicates(nums);
	for(int i=0;i<n;i++)
		cout << nums[i] << " ";
	cout << endl << "length = " << n << endl;
	return 1;
}
