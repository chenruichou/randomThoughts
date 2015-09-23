#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=0;
	for(int i=0;i<nums.size();i++){
		if(nums[i]!=val){
			if(i!=n)
				nums[n]=nums[i];
			n++;			
		}
	}
	return n;
    }
};

int main(){
	Solution sol;
	vector<int> nums={1,4,2,3,4,4,4,5,6,4,8};
	int n = sol.removeElement(nums,4);
	for(int i=0;i<n;i++){
		cout<< nums[i]<<" ";
	}
	cout<<"length = "<< n << endl;
	return 1;
}
