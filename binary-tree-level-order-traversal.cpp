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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        res.clear();
        if(!root){
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);
        
        vector<int> level;
        while(!que.empty()){
            auto node = que.front();
            if(!node){
                res.push_back(level);
                level.clear();
                if(1==que.size()){
                    break;
                }
                que.push(node);
            }else{
                level.push_back(node->val);
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
            que.pop();
        }
        
        return res;
    }
};
