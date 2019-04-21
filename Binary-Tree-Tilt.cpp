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
    int sum;

    int findTiltImpl(TreeNode* root) {
        if(NULL==root){
            return 0;
        }
        int left = findTiltImpl(root->left);
        int right = findTiltImpl(root->right);
        sum += abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        sum = 0;
        findTiltImpl(root);
        return sum;
    }
};
