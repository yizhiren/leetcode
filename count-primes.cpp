vector<bool> bit;
class Solution {
public:
    int countPrimes(int n) {
        if(n==0)return 0;
        if(n==1)return 0;
        bit.resize(n+1);
        int count = 0;
        for(int i=2;i<=n;i++){
            int tmp=i;
            if(!bit[tmp]){
                count ++;
            }
            while(tmp <= n){
                bit[tmp]=true;
                tmp+=i;
            }
        }
        
        return count;
    }
};
