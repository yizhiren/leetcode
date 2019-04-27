/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    queue<TreeNode*> que;
    TreeNode* _root;
    CBTInserter(TreeNode* root) {
        _root = root;
        que.push(root);
        while(1){
            TreeNode* node = que.front();
            if(node->left)que.push(node->left);
            if(node->right)que.push(node->right);
            
            if(!node->left || !node->right){
                break;
            }
            
            que.pop();
        }
    }
    
    int insert(int v) {
        TreeNode* node = que.front();
        TreeNode* newNode = new TreeNode(v);
        
        if(!node->left){
            node->left=newNode;
            que.push(newNode);
            return node->val;
        }
        
        node->right=newNode;
        que.push(newNode);
        que.pop();
        return node->val;
    }
    
    TreeNode* get_root() {
        return _root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
