/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef pair<TreeNode*, int> NodeLevel;
class Solution {
public:
    int levelStopHaveSun;
    NodeLevel nodeLevel;
    bool isCompleteTree(TreeNode* root) {
        if(!root){return true;}
        levelStopHaveSun = 0;
        queue<NodeLevel> nodes;
        nodes.push(NodeLevel(root,1));
        while(!nodes.empty()){
            NodeLevel &nodeLevel = nodes.front();
            if(levelStopHaveSun>0 && nodeLevel.second > levelStopHaveSun+1){
                return false;
            }
            if(levelStopHaveSun>0 && (nodeLevel.first->left || nodeLevel.first->right)){
                return false;
            }
            if(nodeLevel.first->left==NULL && nodeLevel.first->right!=NULL){
                return false;
            }
            if(levelStopHaveSun==0 && (nodeLevel.first->left==NULL || nodeLevel.first->right==NULL)){
                levelStopHaveSun = nodeLevel.second;
            }
            if(nodeLevel.first->left)nodes.push(NodeLevel(nodeLevel.first->left,nodeLevel.second+1));
            if(nodeLevel.first->right)nodes.push(NodeLevel(nodeLevel.first->right,nodeLevel.second+1));
            nodes.pop();
        }
        
        return true;
    }
};
