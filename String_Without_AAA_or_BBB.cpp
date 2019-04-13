class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if(A==0){
            return string("").append(B,'b');
        }
        if(B==0){
            return string("").append(A,'a');
        }
        if(A==B){
            string ret;
            for(int i=0;i<A;i++){
                ret.append("ab");
            }
            return ret;
        }
        
        
        int big = A;
        int lit = B;
        string AB = "ab"; string AAB = "aab";
        if(A<B){
            swap(big,lit);
            AB = "ba";
            AAB = "bba";
        }
        // x + y = lit+1;
        // x + 2y = big;
        // => 2 yuan 2 ci fangcheng
        // => y = lit+1-x
        // => x+2(lit+1-x) = big
        // => 2*lit+2-x = big
        // => x=2*lit+2-big
        
        int x = 2*lit+2-big;
        int y = lit+1-x;
        string ret;
        for(int i=0;i<x;i++){
            ret.append(AB);
        }
        
        for(int i=0;i<y;i++){
            ret.append(AAB);
        }
        
        return ret.substr(0,ret.length()-1);
    }
};
