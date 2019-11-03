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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> level;
        level.push(root);
        bool leftFirst = true;
        while(!level.empty()){
            stack<TreeNode*> tmp;
            vector<int> levelseq;
            while(!level.empty()){
                auto &node = level.top();
                if(node && leftFirst){
                    tmp.push(node->left);
                    tmp.push(node->right);
                    levelseq.push_back(node->val);
                }else if(node && !leftFirst){
                    tmp.push(node->right);
                    tmp.push(node->left);
                    levelseq.push_back(node->val);
                }
                level.pop();
            }
            if(!levelseq.empty())
                    res.push_back(levelseq);
            leftFirst = !leftFirst;
            swap(level,tmp);
        }
        
        return res;
    }
};
