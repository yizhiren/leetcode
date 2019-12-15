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
    bool isValidBST(TreeNode* root,TreeNode*& minnode,TreeNode*& maxnode) {
        if(!root){
            return true;
        }
        TreeNode* leftmin = nullptr;
        TreeNode* leftmax = nullptr;
        bool leftValid = isValidBST(root->left, leftmin,leftmax);
        
        TreeNode* rightmin = nullptr;
        TreeNode* rightmax = nullptr;
        bool rightValid = isValidBST(root->right, rightmin,rightmax);
        
        if (!leftValid || !rightValid){
            return false;
        }
        
        if(leftmax && leftmax->val>=root->val){
            return false;
        }
        
        if(rightmin && rightmin->val<=root->val){
            return false;
        }
        
        minnode = leftmin;
        maxnode = rightmax;
        if(!minnode){
            minnode=root;
        }
        if(!maxnode){
            maxnode = root;
        }
        
        
        return true;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* nodemin = nullptr;
        TreeNode* nodemax = nullptr;
        return isValidBST(root,nodemin,nodemax);
    }
};

///////

class Solution {
    
    vector<int> seq;
public:
    
    void makeSeq(TreeNode* root){
        if(!root){
            return;
        }
        makeSeq(root->left);
        seq.push_back(root->val);
        makeSeq(root->right);
    }
    bool isValidBST(TreeNode* root) {
        seq.clear();
        makeSeq(root);
        int len = seq.size();
        for(int i=0;i<len-1;i++){
            if(seq[i] >= seq[i+1]){
                return false;
            }
        }
        return true;
        
        
    }
};

