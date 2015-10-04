
class Solution {
	std::vector<int> next;
	void makeNext(string &sub){
		int len = sub.length();
		next.resize(len/2);
		int j=-1;
		int i=0;
		next[i]=j;
		while(i<len/2-1){
		    if(j==-1 || sub[i]==sub[j]){
		    	i++;
		    	j++;
		    	next[i]=j;
		    	//printf("[%d]=[%d]\n",i,next[i]);
		    }else{
		    	j=next[j];
		    }
		}

	}
    

public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if(len<=1){
        	return  s;
        }
        //printf("len=%d\n",len);
        makeNext(s);
        int head=0;
        int tail=len-1;
        while(head<tail){
            if(s[head]==s[tail] && tail==head+1){
                break;   
            }else if(head == -1 || s[head]==s[tail]){
        		tail--;
        		head++;
        	}else{
        		head = next[head];

        	}
        }

        string tmp;
        if(head==tail){
            tmp=s.substr(tail+1);
        }else{
            tmp=s.substr(tail);
        }
        reverse(tmp.begin(), tmp.end());
        return tmp+s.substr(tail);
    }
};