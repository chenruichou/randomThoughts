#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       	vector<int> sums(nums.size(),0);
	int curr_sum=0;
	for(int i=0;i<nums.size();i++){
		curr_sum += nums[i];
		sums[i] = curr_sum;
	}
	
	// scan to find curr min and max
	vector<int> min_v(nums.size(),0);
	vector<int> max_v(nums.size(),0);
	int curr_max = 0;
	int curr_min = 999999;
	for(int i=0;i<nums.size();i++){
		if(sums[i]<curr_min){
			min_v[i] = sums[i];
			max_v[i] = sums[i];
			curr_min = min_v[i];
			curr_max = max_v[i];
		}
		else if(sums[i]>curr_max){
			max_v[i] = sums[i];
			min_v[i] = curr_min;
			curr_max = max_v[i];
		}else{
			// propagate, no update
			max_v[i] = curr_max;
			min_v[i] = curr_min;
		}
	}
	
	// find the maximum distance between min and max
	int out = max_v[0]-min_v[0];
	for(int i=1;i<nums.size();i++){
		if(out < (max_v[i]-min_v[i])) out = max_v[i]-min_v[i];	
	}
	
	return out;
	 
    }
    
};


int main(){
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	Solution sol;
	cout << sol.maxSubArray(nums) << endl;
	return 1;
}
