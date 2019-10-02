/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void copyNodeFromBToA(ListNode* a, ListNode* b) {
        a->val = b->val;
    }
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        ListNode* next = cur->next;
        while(next){
            copyNodeFromBToA(cur, next);
            if(next->next==NULL){
                cur->next = NULL;
                delete next;
                break;
            }
            cur = next;
            next = cur->next;
        }
    }
};
