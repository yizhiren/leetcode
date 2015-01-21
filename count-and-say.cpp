

class Solution {
public:
    string countAndSay(int n) {
        if(n<=0)return "";
        if(n==1)return "1";
        
        string str="1";
        int t=1;
        int bufPlace=0;
        while(t<n){
        	int len=str.length();
        	char buf[10240]={
        	    0
            };
        	char ch=str[0];
        	int i=0;int cnt=0;
        	while(i<len){
	        	if(str[i]==ch){
	        		cnt++;
	        		i++;
	        	}else{
	        		buf[bufPlace++]=cnt+'0';
	        		buf[bufPlace++]=ch;
	        		
					ch = str[i++];
	        		cnt=1;
	        	}
	        }
	        if(cnt>0 ){
        		buf[bufPlace++]=cnt+'0';
        		buf[bufPlace++]=ch;
        	}
        	buf[bufPlace]='\0';bufPlace=0;
        	str=buf;
	        t++;
        }
        return str;
    }
};