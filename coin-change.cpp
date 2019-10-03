class Solution {
public:
    map<int, int> cache;
    int coinChangeFromBigest(vector<int>& coins, int amount) {
        if(amount <= 0)return 0;
        if(cache.find(amount) != cache.end()){
            return cache[amount];
        }
        int cnt = -1;
        int len = coins.size();
        for (int i=len-1;i>=0;i--) {
            if (coins[i] <= amount){
                int subRes = coinChangeFromBigest(coins, amount-coins[i]);
                if (subRes >= 0 && cnt==-1){
                    cnt = subRes + 1;
                } else if(subRes >= 0 && subRes +1 < cnt) {
                    cnt = subRes + 1;
                }
            }
        }
        cache[amount] = cnt;
        return cnt;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end()); 
        return coinChangeFromBigest(coins, amount);
    }
};
