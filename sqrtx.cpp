// 二分法

class Solution {
public:
    int mySqrt(int x) {
       if (x<=1)return x;
        
        int l=0;int r=x;int m=0;
        while(l<r){
            m=(r+l)/2;
            if(x/m==m){
                return m;
            }else if(x/m>m){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return x/l<l?l-1:l;
    }
};
