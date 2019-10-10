//递归
class Solution {
public:
    vector<int> res;
    void inorder(TreeNode* root) {
        if(root){
            inorder(root->left);
            res.push_back(root->val);
            inorder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        res.clear();
        inorder(root);
        return res;
    }
};

//////////////////////
// 非递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==0)return res;
        stack<TreeNode*> sk;
        while(root){
            sk.push(root);
            root=root->left;
        }
        while(!sk.empty()){
            auto top = sk.top();
            res.push_back(top->val);
            sk.pop();
            if(top->right){
                root = top->right;
                while(root){
                    sk.push(root);
                    root=root->left;
                }
            }
            
        }
        
        return res;
    }
};
