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
                              && a->val==b->val);
    }
    
    
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            TreeNode* a = q.front();
            q.pop();
            TreeNode* b = q.front();
            q.pop();
            if(!compareTree(a,b)){
                return false;
            }
            if (a && b){
                q.push(a->left);
                q.push(b->right);
                q.push(a->right);
                q.push(b->left);
            }
        }
        return true;
    }
};
