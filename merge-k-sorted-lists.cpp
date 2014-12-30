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
	ListNode MAXNODE;
	Solution():MAXNODE(INT_MAX){}

	int firstTime_fillFailNode(vector<int> &failTree,vector<ListNode *> &kBranch,int index){
		int k=failTree.size()/2;
		if(index>=k){
			return failTree[index];
		}

		int LeftSonWin=firstTime_fillFailNode(failTree,kBranch,2*index);
		int RightSonWin=firstTime_fillFailNode(failTree,kBranch,2*index+1);
		int bigger=LeftSonWin; int liter=RightSonWin;
		if(kBranch[LeftSonWin]->val < kBranch[RightSonWin]->val){
			bigger=RightSonWin;liter=LeftSonWin;
		}
		failTree[index]=bigger;
		if(index==1){
			failTree[0]=liter;
		}
		return liter;
	}
	void firstTime(vector<int> &failTree, vector<ListNode *> &kBranch){
		int k=failTree.size()/2;
		for(int i=0;i<k;i++){
			if(kBranch[i]==NULL){
				failTree[k+i]=k;
			}else{
				failTree[k+i]=i;
			}
		}
		firstTime_fillFailNode(failTree,kBranch,1);
		
	}
    ListNode *mergeKLists(vector<ListNode *> kBranch) {
        int len=kBranch.size();
        if(len==0){return NULL;}
        if(len==1){return kBranch[0];}
        // make k=2^n;
        int k=1;while(k<len)k<<=1;
        
        //make kBranch.size=k+1 , the K th is the INT_MAX
        for(int i=len;i<=k;i++){
        	kBranch.push_back(&MAXNODE);
        }
        
 		// create Fail Tree
        vector<int> failTree;
        failTree.resize(2*k);
        firstTime(failTree,kBranch);
        
        
        //get Merge result;
        ListNode root(0);
        ListNode *curr=&root;
        while(k!=failTree[0]){
        	int Nth=failTree[0];
        	curr->next=kBranch[Nth];
        	curr=curr->next;
        	kBranch[Nth]=kBranch[Nth]->next;
        	if(kBranch[Nth]==NULL){
	        	failTree[k+Nth]=k;
	        }else{
        		failTree[k+Nth]=Nth;//not change
        	}
        	int winNode=Nth+k; int winBranch=failTree[winNode];
        	while(winNode/2>0){
	        	if(kBranch[winBranch]->val>kBranch[failTree[winNode/2]]->val){
	        		int tmp=failTree[winNode/2];
	        		failTree[winNode/2]=winBranch;
	        		winBranch=tmp;
	        	}
	        	winNode/=2;
	        }
	        failTree[0]=winBranch;
        	
        }
        return root.next;
    }
};
