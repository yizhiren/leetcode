class Solution {
    bool isNumberChar(char ch){
        return ch>='0' && ch<='9';
    }
    bool skipRealNumber(string &s, int index, int &next, bool allowPoint=true){
    	next=index; int cnt=0;
        while(isNumberChar(s[next])){
			next++;
			cnt++;
		}
        /**
        	"" false
        	"." false
        	"1." true
        	".1" true
        **/
        
        if( allowPoint && '.'==s[next]){
        	next++;
            while(isNumberChar(s[next])){
				next++;
				cnt++;
			}
        }
        return cnt>0;
    }
    bool checkIsSign(string &s, int index){
        return ( (s[index]=='-' || s[index]=='+')
			&& (isNumberChar(s[index+1]) || s[index+1]=='.')
			);
    }
public:
    bool isNumber(string s) {
        int len=s.length();
        if(len==0)return false;
        int i=0;int j=len-1;

        while(' '==s[i])i++;
        while(' '==s[j])j--;
		//std::cout<<i<<" "<<j<<std::endl;
        if(checkIsSign(s,i)){
            i++;
        }
        if(!skipRealNumber(s,i,i)){
        	return false;
        }
        if('e'==s[i]){
        	i++;
            if(checkIsSign(s,i)){
                i++;
            }
         	if(!skipRealNumber(s,i,i,false)){
        		return false;
        	}
        }
        return i==j+1;
        
    }
};