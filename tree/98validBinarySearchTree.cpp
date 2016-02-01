#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isValidBST(TreeNode *root){
            return isValidBSTSol(root, LONG_MIN, LONG_MAX);
        }

        bool isValidBSTSol(TreeNode* root, long val_min, long val_max) {
            if(!root)
                return true;
            bool fromLeft = true;
            bool fromRight = true;
            if(root->left){
                fromLeft = root->val > root->left->val ? true : false;
                fromLeft = fromLeft && (root->left->val > val_min && root->left->val < root->val);
                if(fromLeft) // if still valid, keep checking further
                    fromLeft = isValidBSTSol(root->left, val_min, root->val);
            }
            if(root->right){
                fromRight = root->val < root->right->val ? true : false;
                fromRight = fromRight && (root->right->val > root->val && root->right->val < val_max);
                if(fromRight) // if still valid, keep checking further
                    fromRight = isValidBSTSol(root->right, root->val, val_max);
            }
            return !(!fromLeft || !fromRight);
        }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(-1);
    //root->left->left = new TreeNode(1);
    //root->right = new TreeNode(4);
    bool out = sol.isValidBST(root);
    cout << out << endl;
    return 1;
}
