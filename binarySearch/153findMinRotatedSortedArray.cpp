class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0;
            int right = nums.size()-1;
            while(left+1<right){
                int mid = (left+right)/2;
                if(nums[left]>nums[mid]){
                    right = mid;
                }else if(nums[right]<nums[mid]){
                    left = mid;
                }else{
                    // all good. return the left-est
                    return nums[left];
                }
            }
            return min(nums[left], nums[right]);
        }
};
