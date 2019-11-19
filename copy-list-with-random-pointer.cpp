/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    map<Node*,Node*> responding;
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        
        Node* newHead = new Node(head->val, nullptr, head->random);
        responding[head] = newHead;
        
        Node* father = newHead;
        while(head->next){
            head = head->next;
            Node* next =new Node(head->val,nullptr, head->random);
            father -> next = next;
            father = next;
            responding[head]=next;
        }
        father = newHead;
        while(father){
            father->random = responding[father->random];
            father = father->next;
        }
        
        return newHead;
    }
};
