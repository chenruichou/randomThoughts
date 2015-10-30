#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
        int searchInsert(vector<int>& nums, int target) {
                int left=0;
                int right = nums.size()-1;
                int out = -1;
                int mid = -1;
                while(left<=right){
                        mid = (left+right)/2;
                        if(nums[mid]>target){
                                right = mid - 1;
                        }else if(nums[mid]<target){
                                left = mid + 1;
                        }else{ //nums[mid]==target
                                out = mid;
                                break;
                        }
                }
                if (out==-1)
                        out = nums[mid]>target ? mid : mid+1;
                return out;
        }
};


int main(){
	Solution sol;
	vector<int> nums = {1,2,4,6,9};
	int target = 5;
	int out = sol.searchInsert(nums,target);
	cout << out << endl;
	return 1;
}
