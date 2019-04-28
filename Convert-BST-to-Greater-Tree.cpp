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
    vector<TreeNode*> nodes;
    void sortBST(TreeNode* root) {
        if(!root)return;
        
        sortBST(root->left);
        nodes.push_back(root);
        sortBST(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        sortBST(root);
        int sum=0;
        for(int i=nodes.size()-1;i>=0;i--){
            nodes[i]->val+=sum;
            sum=nodes[i]->val;
        }
        
        return root;
    }
};
