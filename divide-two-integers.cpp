class Solution {
public:
    int divide(int dividend, int divisor) {
        if(0==divisor){
            return INT_MAX;
        }
        unsigned un_dividend=dividend;
        unsigned un_divisor=divisor;
        int sign=1;
        if(dividend < 0){
            sign=-sign;
            if(dividend==INT_MIN){
            	un_dividend=INT_MAX+1;
            }else{
            	un_dividend=-dividend;
            }
            
        }
        if(divisor<0){
            sign=-sign;
            if(divisor==INT_MIN){
            	un_divisor=INT_MAX+1;
            }else{
            	un_divisor=-divisor;
            }            
        }
        
        ///
        unsigned result=0;
        ///bitset not support in leetcode
        int dividendBit[32]={0};
        int tmpi=0;
        while(tmpi<32){
        	dividendBit[tmpi]=un_dividend%2;
        	un_dividend/=2;
        	tmpi++;
        }
        ///
       	un_dividend=0;
       	int dividendBitIndex=31;

       	for(dividendBitIndex=31;dividendBitIndex>=0;dividendBitIndex--){
       		
	    	un_dividend=(un_dividend<<1)+dividendBit[dividendBitIndex];
			if(un_dividend>=un_divisor){
				un_dividend-=un_divisor;
				result+=(1<<dividendBitIndex);
			}
    	}
    	if(result>INT_MAX && sign >0){
	    	return INT_MAX;
	    }else{
    		return (int)result * sign;
    	}

    }
};
