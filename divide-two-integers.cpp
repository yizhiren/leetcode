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

///////////////////////


// 参考的 https://leetcode.com/problems/divide-two-integers/discuss/448070/C%2B%2B-kinda-shorter-solution(-not-using-long-datatype-)-beats-100
class Solution {
public:
    int getQuotient(int dividend, int divisor){
        int quotient = 0;
        while(dividend >= divisor){
            int multiplier = 1;
            int preDivisor=0;
            int currDivisor = divisor;
            while(currDivisor < (INT_MAX>>1) && dividend > currDivisor){
                preDivisor = currDivisor;
                currDivisor <<= 1;
                multiplier <<= 1;
            }
            if (multiplier > 1){
                quotient += (multiplier >> 1);
            }else{
                quotient += multiplier;
                break;
            }
            dividend -= preDivisor;
        }
        
        return quotient;
    }
    int divide(int dividend, int divisor) {
        int quotient = 0;
        if(divisor == 0) return INT_MAX;
        if(divisor == 1)return dividend;
        if(divisor==-1)return(dividend==INT_MIN)?INT_MAX:-dividend;
        if(dividend==divisor)return 1;
        if(divisor==INT_MIN)return 0;
        
        if(dividend==INT_MIN){
            if(divisor>0)dividend+=divisor;
            else dividend-=divisor;
            quotient++;
        }
        bool sign = (dividend<0) ^ (divisor < 0);
        if(dividend < 0)dividend=-dividend;
        if(divisor<0)divisor=-divisor;
        quotient += getQuotient(dividend,divisor);
        
        return sign ? -quotient:quotient;
    }
};
