class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	int strNum = strs.size();
    	if(strNum==0)return "";
    	
    	string &str = strs[0];    	
    	int maxCommLen=str.length();
    	
    	for(int i=1;i<strNum;i++){
	    	string &str2 = strs[i];
	    	int j=0;
	    	for(j=0;j<min(str.length(),str2.length());j++){

	    		if(str[j]==str2[j]){
		    		continue;
		    	}else{		    		
	    			break;
	    		}
	    	}
	    	if(j<maxCommLen){
				maxCommLen = j;
    		}
	    }
    	
    	return str.substr(0,maxCommLen);
        
        
    }
};