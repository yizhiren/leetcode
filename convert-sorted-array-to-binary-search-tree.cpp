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
    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
        if(low > high){
            return 0;
        }
        if(low==high){
            return new TreeNode(nums[low]);
        }
        int midnode = (low+high)/2;
        TreeNode *parent = new TreeNode(nums[(low+high)/2]);
        parent->left = sortedArrayToBST(nums,low,midnode-1);
        parent->right = sortedArrayToBST(nums,midnode+1,high);
        
        return parent;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
};
