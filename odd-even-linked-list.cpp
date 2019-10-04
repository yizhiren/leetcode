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
    ListNode* oddEvenList(ListNode* head) {
        if (head==0 || head->next==0){
            return head;
        }
        
        ListNode *odd = head;//奇数
        ListNode *even = head->next;//偶数
        ListNode *evenHead = even;
        while(1){
            if(even){
                if(even->next){
                    odd->next = even->next;
                    odd = odd->next;
                } else {
                    odd->next = evenHead;
                    break;
                }
            }
            if(odd){
                even->next = odd->next;
                if(odd->next){
                    even=even->next;          
                } else {
                    odd->next = evenHead;
                    break;
                }
            }

        }
        
        return head;
    }
};
