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
    void addNewNode(ListNode *&ln, ListNode *&lncurr,int val)
    {
		if(ln==NULL){
			ln=new ListNode(val);
			lncurr=ln;
			
		}else{
			lncurr->next=new ListNode(val);
			lncurr=lncurr->next;
		}
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	int jump=0;
	ListNode *ln=NULL,*lncurr=NULL;
	while(l1 && l2){
		int val=l1->val+l2->val+jump;
		jump=val/10;
		val=val%10;
		addNewNode(ln,lncurr,val);
		l1=l1->next;l2=l2->next;
	}
	while(l1){
		int val=l1->val+jump;
		jump=val/10;
		val=val%10;
		addNewNode(ln,lncurr,val);
		l1=l1->next;
	}
	
	while(l2){
		int val=l2->val+jump;
		jump=val/10;
		val=val%10;
		addNewNode(ln,lncurr,val);
		l2=l2->next;
	}
	if(jump>0){
	    addNewNode(ln,lncurr,jump);
	}
	return ln;
    }
};
