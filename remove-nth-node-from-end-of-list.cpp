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


//////////////////
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        for(int i=0;i<n;i++){
            if(!first)return nullptr;
            first=first->next;
        } 
        if(!first){
            ListNode* ret = head->next;
            ListNode* toDel = head;
            delete toDel;
            return ret;
        }
        ListNode* second = head;
        while(first->next){
            first=first->next;
            second=second->next;
        }
        ListNode* toDel = second->next;
        second->next=toDel->next;
        delete toDel;
        
        return head;
    }
};

