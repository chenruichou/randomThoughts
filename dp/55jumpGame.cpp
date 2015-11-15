#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        bool canJump(vector<int> & nums){
            bool out = findJump(nums, 0);
            return out;
        }
        bool findJump(vector<int> &nums, int indx){
            if(indx==nums.size()-1) return true;
            if(indx>nums.size()-1) return false;

            bool out=false;
            for(int i=1; i<=nums[indx]; i++){
                out = out || findJump(nums, indx+i);
            }
            return out;
        }

};
int main(){
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    bool out = sol.canJump(nums);
    cout << out << endl;
    return 1;
}
