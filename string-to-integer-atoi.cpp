class Solution {
public:
    int atoi(const char *str) {
        if(!str){
        	return 0;
        }
        int val=0;int sign=1;
        
        while(str && (*str=='\t' || *str==' '))str++;
        if('-'==*str){
            str++;
        	sign=-1;
        }else if('+'==*str){
            str++;
        	sign=1;
        }
        while(str && *str=='0')str++;
        
        while(str){
        	if(*str >= '0' && *str <='9'){
        		int adding=*str-'0';
        	    if(sign>0){
        	        if(INT_MAX/10 < val || (INT_MAX/10==val && INT_MAX%10<adding)){
        	        	return INT_MAX;
        	        }        	        
        	    }else{
    	        	if(INT_MIN/10 > -val || (INT_MIN/10==-val && INT_MIN%10>-adding)){
	        	    	return INT_MIN;
	        	    }
    	        }
	        	val=val*10+*str-'0';
	        	str++;
	        }else{
        		break;
        	}
        	
        }
        val*=sign;
        return val;
        
    }
};