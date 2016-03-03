#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        void flatten(TreeNode* root) {

        }
};
int main(){
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    sol.flatten(root);

    while(root){
        cout << root->val << "->";
        root = root->right;
    }
    cout << endl;
    return 1;
}
