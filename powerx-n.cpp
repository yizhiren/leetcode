class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        long nn=n;
        if (nn<0){
            x = 1/x;
            nn=-nn;
        }
        double one = 1;
        while(nn>1){
            if(nn%2==1){
                one *= x;
            }
            x *= x;
            nn/=2;
        }
        
        return one * x;
    }
};
