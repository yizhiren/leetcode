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
    int getNumOfTree(TreeNode* root) {
        if(!root)return 0;
        return getNumOfTree(root->left) + getNumOfTree(root->right) + 1;
        
    }
    int getCoinOfTree(TreeNode* root) {
        if(!root)return 0;
        return getCoinOfTree(root->left)+ getCoinOfTree(root->right) + root->val;
    }
    int distributeCoins(TreeNode* root) {
        if(!root)return 0;
        
        int leftNum = getNumOfTree(root->left);
        int leftCoin = getCoinOfTree(root->left);
        
        int mov = 0;
        if(leftNum != leftCoin) {
            root->left->val += leftNum-leftCoin;
            root->val -= leftNum-leftCoin;
            mov += abs(leftNum-leftCoin);
        }
        //cout << mov << endl;
        
        if(root->val-1){
            mov += abs(root->val-1);
            root->right->val += root->val-1;
            root->val = 1;
        }
        //cout << mov << endl;
        
        return mov + distributeCoins(root->left) + distributeCoins(root->right);
    }
};
