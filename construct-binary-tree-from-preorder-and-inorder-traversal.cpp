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
    TreeNode* buildTree(vector<int>& preorder, int pre_low, int pre_high,
                        vector<int>& inorder, int in_low,int in_high) {
        if(pre_low>pre_high){
            return nullptr;
        }
        if(pre_low==pre_high){
            return new TreeNode(preorder[pre_low]);
        }
        
        int mid_in_inorder=0;
        for(mid_in_inorder=in_low;mid_in_inorder<=in_high;mid_in_inorder++){
            if(inorder[mid_in_inorder]==preorder[pre_low]){
                break;
            }
        }
        
        TreeNode* root = new TreeNode(preorder[pre_low]);
        root->left = buildTree(preorder, pre_low+1, pre_low+mid_in_inorder-in_low,
                              inorder, in_low, mid_in_inorder-1);
        root->right = buildTree(preorder,pre_low+mid_in_inorder-in_low+1, pre_high,
                              inorder, mid_in_inorder+1, in_high);  
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,
                       inorder,0,inorder.size()-1);
    }
};
