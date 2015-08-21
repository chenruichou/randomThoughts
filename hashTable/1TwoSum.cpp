#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> out;
	return out;        
    }
};


int main(){
	int nums[] = {2,3,4,5,6,7,8};
	vector<int> nums_v;
	nums_v.assign(nums,nums+6);
	Solution s;	
	int tar=10;
	vector <int> out = s.twoSum(nums_v,tar);
	return 0;
}
