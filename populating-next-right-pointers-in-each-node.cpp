/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root){
            return nullptr;
        }
        
        queue<Node*> que;
        que.push(root);
        que.push(nullptr);
        
        while(!que.empty()){
            Node* node = que.front();
            que.pop();
            if(node==nullptr){
                if(!que.empty()){
                    que.push(node);
                }
                continue;
            }
            
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }
            
            node->next = que.front();
        }
        
        return root;
    }
};
