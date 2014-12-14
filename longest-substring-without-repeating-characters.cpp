class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	map<char,int> container;
    	map<char,int>::iterator iter;
		
		int low=0;int high=0; int len=s.length();int longest=0;
        while(high<len){
        	if(container.find( s[high] )==container.end()){
	        	container[s[high++]]=1;				 	
	        }else{
        		if(container.size()>longest){
		        	longest=container.size();
		        }
		        iter = container.find( s[low++] );
		        container.erase(iter);
        	}
        } 
        if(container.size()>longest){
		   	longest=container.size();
        }
        return longest;
    }
};
