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

    bool isCompleteTree(TreeNode* root) {
        if(!root){return true;}
        bool isNullMeet = false;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* node = nodes.front();
            if(NULL==node){
                isNullMeet = true;
            }else{
                if(isNullMeet){
                    return false;
                }
                nodes.push(node->left);
                nodes.push(node->right);
            }
            
            nodes.pop();
        }
        
        return true;
    }
};
