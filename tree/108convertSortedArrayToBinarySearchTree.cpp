#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
    public:
        TreeNode *sortedArrayToBST(vector<int> &nums){
            if(nums.size()==0) return NULL;

            TreeNode *root = new TreeNode(nums[nums.size()/2]);
            auto rootItr = nums.begin()+nums.size()/2;
            if(rootItr-1>=nums.begin()){
                vector<int> nums_left(nums.begin(),rootItr-1);
                parseBST(root->left, nums_left);
            }
            if(rootItr+1<=nums.end()-1){
                vector<int> nums_right(rootItr+1, nums.end()-1);
                parseBST(root->right, nums_right);
            }
            return root;
        }
        void parseBST(TreeNode *curr, vector<int> &nums){
            if(nums.size()==0)
                return;
            auto rootItr = nums.begin()+nums.size()/2;
            curr = new TreeNode(*rootItr);
            if(rootItr-1>=nums.begin()){
                vector<int> nums_left(nums.begin(),rootItr-1);
                parseBST(curr->left, nums_left);
            }
            if(rootItr+1<=nums.end()-1){
                vector<int> nums_right(rootItr+1, nums.end()-1); 
                parseBST(curr->right, nums_right);
            }
            return;
        }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6};
    TreeNode *root = sol.sortedArrayToBST(nums);
    cout << root->left->right->val << endl;
    return 1;
}
