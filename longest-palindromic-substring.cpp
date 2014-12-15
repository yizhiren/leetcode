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
