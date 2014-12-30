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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len=0;
        ListNode *tmp=head;
        while(tmp){
            len++;
            tmp=tmp->next;
        }
        int m=len-n;
        //assert(m>=0);

        ListNode *del=head;
        if(m==0){
            head=del->next;
            delete del;
        }else{
            ListNode *beforeDel=del;
            while(m>0){
                m--;
                beforeDel=del;
                del=del->next;
            }
            beforeDel->next=del->next;
            delete del;
        }

        return head;
    }
};
