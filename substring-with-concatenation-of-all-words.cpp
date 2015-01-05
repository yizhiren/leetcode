
class CharNode{
	public:
	int val;
	CharNode* next[26];
	CharNode(){
		for(int i=0;i<26;i++){
			next[i]=NULL;
		}
	}
	
	~CharNode(){
		for(int i=0;i<26;i++){
			delete next[i];
		}
	}
};



class Solution {

public:
	CharNode root;
	int wordLen;
	int getIndex(char ch){
		int idx=ch-'a';
		if(ch<='Z'){idx=ch-'A';}
		return idx;
	}

	void makeRoot(vector<string> &L){
		int len=L.size();
		wordLen = L[0].length();
		for(int i=0;i<len;i++){
        	string word=L[i];
        	CharNode* curr=&root;
        	for(int j=0;j<wordLen;j++){
        		int idx=getIndex(word[j]);
	        	if(curr->next[idx]==NULL){
	        		curr->next[idx]=new CharNode();
	        	}
	        	curr=curr->next[idx];
	        }
	        curr->val=i;
        }
	}
	
	int getStringIndex(string S,int pos=0){
		CharNode* curr=&root;
    	int len=S.length();

    	for(int i=pos;i<min(pos+wordLen,len);i++){
        	int idx=getIndex(S[i]);	        	
        	curr=curr->next[idx];
        	if(curr==NULL){
	        	break;
	        }
	        if(i==pos+wordLen-1){
        		return curr->val;
        	}
    	}
    	return -1;
	}
	
	vector<int> getSortedAnswer(vector<string> &L){
		int len=L.size();
		vector<int> result;
		for(int i=0;i<len;i++){
			int idx=getStringIndex(L[i]);//must not -1
			result.push_back(idx);
		}
		sort(result.begin(),result.end());
		return result;
	}
	
	vector<int> makeMatchList(string &S){
		vector<int> result;
		int len=S.length();
		for(int i=0;i<len;i++){
			result.push_back(getStringIndex(S,i));
		}
		return result;
	}
	
	vector<int> getSortedMatch(vector<int> &matchList,int idx,int len){
		vector<int> result;
		for(int i=0;i<len;i++){
			if(matchList[idx]==-1){
				return vector<int>();
			}
			result.push_back(matchList[idx]);
			idx+=wordLen;
			
		}
		sort(result.begin(),result.end());
		return result;
	}
	
    vector<int> findSubstring(string S, vector<string> &L) {
        int len=L.size();
        if(len==0)return vector<int>();
		
		makeRoot(L);        
        vector<int> result;
        int matchLen=len*wordLen;
        int slen=S.length();
        
        vector<int> sortedAnswer=getSortedAnswer(L);
        vector<int> matchList=makeMatchList(S);

		for(int i=0;i<=slen-matchLen;i++){
			vector<int> sortedMatch = getSortedMatch(matchList,i,len);
			if(sortedMatch==sortedAnswer){
				result.push_back(i);
			}
		}      

        return result;
    }
};
