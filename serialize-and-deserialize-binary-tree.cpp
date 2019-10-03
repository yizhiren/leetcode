class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        ss << root;
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream ss(data);
        long ptr;
        ss >> hex >>  ptr;
        
        return (TreeNode*)ptr;
    }
};


////////////////////////////

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            if (node==NULL){
                ss << " " << "NULL";
            } else {
                ss << " " << node->val;
                q.push(node->left);
                q.push(node->right);
            }
            q.pop();
        }
        //cout << ss.str() << endl;
        return ss.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }
        stringstream ss(data);
        string val;
        ss  >> val;
        //cout << "root " << val << endl;
        TreeNode *root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();

            ss  >> val;
            //cout << "left " << val << endl;
            if (val=="NULL"){
                node->left=NULL;
            } else {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            
            ss  >> val;
            //cout << "right " << val << endl;
            if (val=="NULL"){
                node->right=NULL;
            } else {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
            
            q.pop();
        }
        
        return root;
        
    }
};

