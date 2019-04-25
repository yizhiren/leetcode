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
    int X;
    int Y;
    int levelX;
    int levelY;
    TreeNode* xparent;
    TreeNode* yparent;
    
    bool isCousins(TreeNode* root, int x, int y) {
        X=x;
        Y=y;
        levelX=0;
        levelY=0;
        xparent=0;
        yparent=0;
        
        findLevel(NULL,root,1);
        return (levelX==levelY) && (xparent!=yparent);
    }
    void findLevel(TreeNode* parent, TreeNode* son,int level) {
        if(!son){return;}
        
        if(son->val==X){
            levelX=level;
            xparent=parent;
            //cout << "x:" << levelX << "," << xparent->val << endl;
        }
        if(son->val==Y){
            levelY=level;
            yparent=parent;
            //cout << "y:" << levelY << "," << yparent->val << endl;
        }
        
        if(!yparent || !xparent){
            findLevel(son,son->left,level+1);
            findLevel(son,son->right,level+1);
        }
        
    }
};
