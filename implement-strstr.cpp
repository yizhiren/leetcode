class Solution {
public:
    vector<int> pback;
    void makeBack(char * needle){
    	int len=strlen(needle);         
        pback.resize(len);
		if(len==0)return;
		
        int back=-1;
        int curr=0;
        pback[curr]=back;
        while(curr<len-1){
            if(back==-1 || needle[back]==needle[curr]){
                back++;curr++;
                pback[curr]=back;
            }else{
                back=pback[back];
            }
        }
    } 
    
    int strStr(char *haystack, char *needle) {
        if(!haystack || !needle)return -1;
        makeBack(needle);
        
        int hayindex=0;int neindex=0;
        while(neindex==-1 || needle[neindex] && haystack[hayindex]){
            if(haystack[hayindex]==needle[neindex] || neindex==-1){
                hayindex++;neindex++;
            }else{
                neindex=pback[neindex];
            }
        }
        
        if(!needle[neindex]){
            return hayindex-neindex;
        }else{
            return -1;
        }
    }
};