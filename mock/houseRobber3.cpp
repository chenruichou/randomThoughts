/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        // memorization
        unordered_map<TreeNode *, int> m; // map treeNode to the max money
        return solRob(root, false, m);
    }
    int solRob(TreeNode *root, bool parentUsed, unordered_map<TreeNode *, int> &m){
        if(!root)
            return 0;
        if(m.count(root)>0){
            return m[root];
        }else{
            if(parentUsed){
                m[root] = solRob(root->left,false,m)+solRob(root->right,false,m);
                return m[root];
            }else{
                unordered_map<TreeNode *, int> m_bkp(m);
                int used = root->val+solRob(root->left,true,m_bkp)+solRob(root->right,true,m_bkp);
                int notUsed = solRob(root->left,false,m)+solRob(root->right,false,m);
                if(used>=notUsed){
                    m = m_bkp;
                    m[root] = used;
                }else{
                    m[root] = notUsed;   
                }
                return m[root];
            }
        }
    }
};


