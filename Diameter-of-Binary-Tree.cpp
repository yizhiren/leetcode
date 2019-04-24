// 递归函数临时变量达到4个就会报栈溢出

class Solution {
public:
    int result;
    int getTreeHeight(TreeNode* root) {
        if(!root)return 0;
        int left = getTreeHeight(root->left);
        int right = getTreeHeight(root->right);
        
        if(left+right > result){
            result = left+right;
        }
        
        return max(left,right)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){return 0;}
        result =0;
        getTreeHeight(root);
        return result;

    }
};
