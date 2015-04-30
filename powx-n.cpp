class Solution {
    int getMaxBit(unsigned n){
        int i=0;
        while(n){
            i++;
            n>>=1;
        }
        return i;
    }
public:
    double myPow(double x, int n) {
        int sign=1;
        if(n<0){
            n=-n;
            sign=-1;
        }
        int bitcnt=getMaxBit(n);
        double result=1;
        double tmpval=x;
        for(int i=0;i<bitcnt;i++){
            
            if(n&(1<<i))result*=tmpval;
            tmpval=tmpval*tmpval;
        }
        if(sign==-1)result=1/result;
        return result;
    }
};