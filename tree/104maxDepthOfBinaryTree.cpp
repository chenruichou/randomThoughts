#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
    public:
        int maxDepth(TreeNode *root){
            if(root==NULL)
                return 0;
            return max(maxDepth(root->left),maxDepth(root->right))+1;
        }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(5);
    int out = sol.maxDepth(root);
    cout << out << endl;
    return 1;
}
