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
    int getListLen(ListNode* head){
        int len=0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* getPart1Head(ListNode* head, int len) {
        int part1Len = len/2;
        while(--part1Len > 0){
            head = head -> next;
        }
        return head;
    }
    
    ListNode* getPart2Head(ListNode* head, int len) {
        int part2Dist = (len+1)/2;
        while(part2Dist-- > 0){
            head = head -> next;
        }
        return head;
    }
    
    void revertNextNode(ListNode* pre,ListNode* next) {
        if (next!=NULL){
            revertNextNode(next,next->next);
            next->next = pre;
        }
    }
    
    void revertList(ListNode* head) {
        revertNextNode(head,head -> next);
        head->next = NULL;
    }
    
    void revertList2(ListNode* head) {
        ListNode* p0 = head;
        ListNode* p1 = head->next;
        ListNode* p2 = p1?p1->next:NULL;
        

        while(p1){
            p1 -> next = p0;
            p0 = p1;
            p1 = p2;
            p2 = p1?p1->next:NULL;
        }

        head -> next = NULL;
    }
    
    bool cmpTwoList(ListNode* part1, ListNode* part2) {
        while(part1 && part2) {
            if(part1->val != part2->val){
                return false;
            }
            part1 = part1->next;
            part2 = part2->next;
        }
        return part1==NULL && part2 == NULL;
    }
    
    bool isPalindrome(ListNode* head) {
        int len = getListLen(head);
        if(len <= 1){
            return true;
        }
        ListNode* part1Head = getPart1Head(head,len);
        ListNode* part2Head = getPart2Head(head,len);
        part1Head -> next = NULL;
        //revertList(head);
        revertList2(head);
        return cmpTwoList(part1Head,part2Head);
    }
};
