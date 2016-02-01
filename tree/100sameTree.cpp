#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q){
            if(!p && !q)
                return true;
            if(!p && q)
                return false;
            if(p && !q)
                return false;
            if(p->val!=q->val)
                return false;
            else
                return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) || \
                     (isSameTree(p->left, q->right) && isSameTree(p->right, q->left)); 
        }
};


int main(){
    Solution sol;
    TreeNode *p = new TreeNode(2);
    p->left = new TreeNode(1);
    p->right = new TreeNode(3);
    TreeNode *q = new TreeNode(2);
    q->right = new TreeNode(1);
    q->left = new TreeNode(3);
    bool out = sol.isSameTree(p, q);
    cout << out << endl;
    return 1;
}
