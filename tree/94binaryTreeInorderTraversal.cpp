#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root){
            vector<int> out;
            if(root!=NULL)
                getInorderVal(root,out);       
            return out;
        }
        void getInorderVal(TreeNode *root, vector<int> &out){
            if(root->left != NULL){
                getInorderVal(root->left, out);
            }
            if(root != NULL){
                out.push_back(root->val);
            }
            if(root->right != NULL){
                getInorderVal(root->right, out);
            }
            return;
        }
};

class Solution2 { // iteration version
    public:
        vector<int> inorderTraversal(TreeNode *root){
            vector<int> out;
            stack<TreeNode*> s;
            TreeNode *curr = root;
            while(curr || !s.empty()){
                if(!curr){
                    // no nodes, expand pushed nodes
                    curr = s.top();
                    s.pop();
                    out.push_back(curr->val);
                    curr = curr->right;
                }else{
                    // push nodes
                    s.push(curr);
                    curr = curr->left;
                }
            }
            return out;
        }

};

int main(){
    Solution2 sol; 
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    (root->right)->left = new TreeNode(3);
    vector<int> out = sol.inorderTraversal(root);
    for(int i=0; i<out.size();i++){
        cout << out[i] << " ";
    }
    cout <<endl;
    return 1;
}
