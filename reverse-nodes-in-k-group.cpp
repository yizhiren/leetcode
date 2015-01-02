/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool isNodeEnough(ListNode *curr,int k){
        int n=0;
		while(n<k && curr){
			curr=curr->next;
			n++;
		}
		return n==k;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
    	if(k<=1)return head;
    	ListNode *first=NULL,*second=NULL,*third=NULL,*prev=NULL;
		
		ListNode virtualRoot(0);
		prev=&virtualRoot;
		prev->next=head;//prev->next always record the original next node
		
		first=head;
		bool nodeEnough=isNodeEnough(first,k);
		
		while(nodeEnough){
			second=first->next;
			third=second->next;
			//reverse one by one
			for(int i=2;i<=k;i++){
				second->next=first;
				first=second;
				second=third;
				if(second)third=second->next;
			}
			ListNode *newPrev=prev->next;
			newPrev->next=second;
			prev->next=first;
			first=second;
			prev=newPrev;
			
			nodeEnough=isNodeEnough(first,k);
		}

		return virtualRoot.next;				    
    }
};
