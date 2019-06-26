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
    bool compareTree(TreeNode* a,TreeNode* b) {
        return (!a && !b) || (a && b 
                              && a->val==b->val 
                              && compareTree(a->left,b->right)
                              && compareTree(a->right,b->left));
    }
    
    
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return compareTree(root->left,root->right);
        
    }
};
