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
    int vv;
    int dd;
    
    void walkTree(TreeNode* root, int d) {
        if(!root)return;
        
        if(d==dd-1){
            TreeNode* newLeftRoot = new TreeNode(vv);
            newLeftRoot->left = root->left;
            root->left = newLeftRoot;

            TreeNode* newRightRoot = new TreeNode(vv);
            newRightRoot->right = root->right;
            root->right = newRightRoot;
        }else{
            walkTree(root->left,d+1);
            walkTree(root->right,d+1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {        
        if(d<=1){
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        
        vv=v;
        dd=d;
        walkTree(root,1);
        return root;
    }
};
