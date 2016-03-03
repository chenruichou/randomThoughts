#include<iostream>
#include <stdlib.h>
#include<vector>
using namespace std;

class Solution{
    public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int v):val(v),left(NULL),right(NULL){}
    };
    bool isBalanced(TreeNode *root){
        return getDepth(root)==-1 ? false : true;
    }
    int getDepth(TreeNode *root){
        if(!root)
            return 0;
        int depth_left = getDepth(root->left);
        int depth_right = getDepth(root->right);
        if(depth_left==-1 || depth_right==-1)
            return -1;
        if(abs(depth_left-depth_right)>1)
            return -1;
        else{
            return max(depth_left,depth_right)+1;
        }
    }
};

int main(){
    Solution sol;
    Solution::TreeNode *root = new Solution::TreeNode(2);
    root->left = new Solution::TreeNode(1);
    root->left->left = new Solution::TreeNode(0);
    root->left->left->right = new Solution::TreeNode(5);
    root->right = new Solution::TreeNode(3);
    cout << sol.isBalanced(root) << endl;
    return 1;
}
