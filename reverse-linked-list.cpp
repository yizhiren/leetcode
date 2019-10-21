/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* newHead;
public:
    ListNode** GetItsNext(ListNode* node){
        if(!node){
            return &newHead;
        }
        ListNode** itsNext = GetItsNext(node->next);
        *itsNext = node;
        return &node->next;
        
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        newHead = nullptr;
        ListNode** itsNext = GetItsNext(head);
        *itsNext = nullptr;
        
        return newHead;
    }
};

///////////////

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        
        ListNode* n1=nullptr,* n2=nullptr,* n3=nullptr;
        n1=head;
        if(n1){
            n2=n1->next;
        }
        if(n2){
            n3=n2->next;
        }
        
        head->next = NULL;
        
        while(n2){
            n2->next=n1;
            n1 = n2;
            n2 = n3;
            if(n3){
                n3=n3->next;
            }
        }
        
        return n1;
    }
};
