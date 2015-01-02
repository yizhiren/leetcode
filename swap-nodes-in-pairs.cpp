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
    ListNode *swapPairs(ListNode *head) {
    	ListNode *prev=NULL,*first=NULL,*second=NULL,*third=NULL;
    	first=head;
    	if(first){
	    	second=first->next;
	    }
	    if(second){
    		third=second->next;
    	}
    	ListNode virtualRoot(0);
    	prev=&virtualRoot;
    	prev->next=head;
    	
		while(first && second){
			second->next=first;
			first->next=third;
			prev->next=second;
			
			prev=first;
			first=third;
			
			if(first){
				second=first->next;	
			}else{
				second=NULL;
			}
			if(second){
				third=second->next;
			}else{
				third=NULL;	
			}
		}
		return virtualRoot.next;		   
    }
};


