class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        bool map[1000][1000]={
        	0
        };
        int maxlen=0;int startpos=0;
        for(int j=0;j<len;j++){
        	for(int i=0;i<len-j;i++){
        		if(j==0){
		        	map[i][i+j]=true;
		        }else if(j==1){
        			map[i][i+j]=(s[i]==s[i+j]);
        		}else{
		        	map[i][i+j]=map[i+1][i+j-1]&&(s[i]==s[i+j]);
		        }

				if(map[i][i+j] && j+1>maxlen){
			       	maxlen=j+1;
			       	startpos=i;
	   			}	
	        }	
        }

        return s.substr(startpos,maxlen);
    }
};


//////////////////////

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();  
        int maxlen=0;int startpos=0;
        for(int i=0;i<len;i++){
            int j=0;
            while(i-j>=0 && i+j<len){
                if(s[i-j]==s[i+j]){
                   j++;
                }else{
                    break;
                }
            }
            j--;
            if(1+2*j > maxlen){
                maxlen = 1+2*j;
                startpos = i-j;
            }
        }
        for(int i=0;i<len;i++){
            int j=0;
            while(i-j>=0 && i+1+j<len){
                if(s[i-j]==s[i+1+j]){
                   j++;
                }else{
                    break;
                }
            }
            if(2*j > maxlen){
                maxlen = 2*j;
                startpos = i-j+1;
            }
        }
        return s.substr(startpos,maxlen);
    }

}

