#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> out;
            if(!root) return out;
            vector<int> out_cand;
            queue<TreeNode *> q;
            queue<int> l;
            int curr_level = 0;
            q.push(root);
            l.push(curr_level);
            while(!q.empty()){
                TreeNode *curr = q.front();
                int level = l.front();
                q.pop();
                l.pop();
                if(level>curr_level){
                    out.push_back(out_cand);
                    out_cand.clear();
                    curr_level = level;
                }
                out_cand.push_back(curr->val);
                level++;
                if(curr->left){
                    q.push(curr->left);
                    l.push(level);
                }
                if(curr->right){
                    q.push(curr->right);
                    l.push(level);
                }
            }
            // push for the last layer
            out.push_back(out_cand);
        return out;
        }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(0);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    vector<vector<int>> out = sol.levelOrder(root);
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}
