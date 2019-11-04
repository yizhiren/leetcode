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
    
    int k_;
    int cnt_;
    int res_;
    
    bool walkTree(TreeNode* root) {
        if(!root){
            return false;
        }
        
        if(walkTree(root->left)){
            return true;
        }
        
        cnt_++;
        if(cnt_==k_){
            res_=root->val;
            return true;
        }
        
        if(walkTree(root->right)){
            return true;
        }
        
        return false;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        k_=k;
        cnt_=0;
        res_=0;
        walkTree(root);
        return res_;
    }
};
