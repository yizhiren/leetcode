class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(max(n+1,3));
        
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++){
            int s = 0;
            for(int j=0;j<i;j++){
                s+= dp[j]*dp[i-j-1];
            }
            dp[i] = s;
        }
        
        return dp[n];
    }
};
