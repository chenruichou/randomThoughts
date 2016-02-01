#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	TreeNode *left;
	TreeNode *right;
	int val;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
		return true;
	bool fromLeft = true;
	bool fromRight = true;
	if(root->left){
		fromLeft = true ? root->val > root->left->val : false;
	}
	if(root->right){
		fromRight = true ? root->val < root->right->val : false;
	}
	
	return !(!fromLeft || !fromRight);
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->right = new TreeNode(4);
	bool out = sol.isValidBST(root);
	cout << out << endl;
	return 1;
}
