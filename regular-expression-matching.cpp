class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if('\0'==*p && '\0'==*s){
        	return true;
        }
		if('\0'==*p && '\0'!=*s){
        	return false;
        }

        if(*(p+1) != '*'){
        	if('\0'==*s){
	        	return false;
	        }
        	return (*p=='.' || *p==*s) && isMatch(++s,++p);
        }else{
        	if(*p == '*'){
	        	return false; // invalid pattern **
	        }	        
	        
        	const char *ptrString=s;
        	const char *ptrPattern=p;
        	const char *ptrPatternNext=p+2;
        	if('\0'==*ptrString){
	        	return isMatch(ptrString,ptrPatternNext);
	        }
        	if(isMatch(ptrString,ptrPatternNext)){
        		return true;
        	}
        	while(*ptrPattern == '.' || *ptrPattern==*ptrString){
	        	if(isMatch(++ptrString,ptrPatternNext)){
	        		return true;
	        	}
	        	if('\0'==*ptrString){
	        		break;
	        	}
	        };
	        return isMatch(ptrString,ptrPatternNext);

        }
    }
};