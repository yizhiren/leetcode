class Solution {
	const char * lastS;
	const char * lastP;

public:Solution() {
		lastP = NULL;
		lastS = NULL;
	}
public:
    bool isMatch(const char *s, const char *p) {
    	if(*s != '\0'){
	    	if(*p==*s || *p=='?'){
	    		return isMatch(s+1, p+1);
	    	}else if(*p=='*') {
				//over write the pre lastS and lastP, this is the key point to decrease the complex			
				lastS=s;
				lastP=p;
				return isMatch(s,p+1);
	    	}else if(lastS && lastP){
	    		s=++lastS;
	    		p=1+lastP;	  
				return isMatch(s,p);
	    	}else{
	    		return false;
	    	}
	    	
	    }
   		while(*p){
			if(*p++!='*')return false;   	
	    }
        return true;
    }
};


class Solution {

public:
    bool isMatch(const char *s, const char *p) {
  		const char * lastS = NULL;
		const char * lastP = NULL;
    	while(*s != '\0'){
	    	if(*p==*s || *p=='?'){
	    		s++;p++;
	    	}else if(*p=='*') {
				//over write the pre lastS and lastP, this is the key point to decrease the complex			
				lastS=s;
				lastP=p;
				p++;
	    	}else if(lastS && lastP){
	    		//if * has appeared, then the only way to prove it not match is 
	    		//try all s with lastP+1, until *s == '\0'.
	    		s=++lastS;
	    		p=1+lastP;
	    	}else{
	    		return false;
	    	}
	    	
	    }
	    // if (*s=='\0') then there is no need to roll back to the "++lastS", because 
	    // if current situation it not match, then the "++lastS" will not match also.
   		while(*p){
			if(*p++!='*')return false;   	
	    }
        return true;
    }
};


