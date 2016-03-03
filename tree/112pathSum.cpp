#include<vector>
#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

class Solution {
    public:
        bool hasPathSum(TreeNode* root, int sum) {
            if(!root){
                if(sum==0)
                    return true;
                else
                    return false;
            }
            return hasPathSum(root->left,sum - root->val) || \
                    hasPathSum(root->right, sum - root->val);
        }
        
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    cout << sol.hasPathSum(root,7) << endl;

}
