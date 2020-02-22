class Solution {
public:
    
    int numDecodings(string s) {
        
        if(s.empty() || s[0]=='0'){
            return 0;
        }
        int len = s.length();
        vector<int> dp(len+1,1);

        for(int i=2;i<=len;i++){
            if(s[i-1]=='0'){
               if(s[i-2]=='1' || s[i-2]=='2'){
                   dp[i] = dp[i-2];
               }else{
                   return 0;
               }
            }else{
                if(s[i-2]>'2' || s[i-2]=='0' || 
                   s[i-2]=='2' && s[i-1]>'6'){
                    dp[i] = dp[i-1];
                }else {
                    dp[i] = dp[i-1] + dp[i-2];
                }
            }

        }
        
        return dp[len];
    }
};
