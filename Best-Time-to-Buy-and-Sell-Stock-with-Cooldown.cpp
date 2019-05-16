class Solution {
public:
    map<pair<int,int>,int> mem;
    int maxProfitOfRange(const vector<int>& prices, int st, int ed) {
        if(st+1 >= ed){
            return 0;
        }
        if(mem.find(pair<int,int>(st,ed)) != mem.end()){
            return mem[pair<int,int>(st,ed)];
        }
        
        int maxprofit = maxProfitOfRange(prices, st+1, ed);
        int inprice = prices[st];
        int maxSellPrice = inprice;
        for(int i=st+1;i<ed;i++){
            if(prices[i] > maxSellPrice){
                int thisprofit = (prices[i]-inprice) + maxProfitOfRange(prices, i+2, ed);
                if(thisprofit > maxprofit){
                    maxprofit = thisprofit;
                }
                maxSellPrice =prices[i];
            }
        }
        
        mem[pair<int,int>(st,ed)] = maxprofit;
        return maxprofit;
    }
    int maxProfit(const vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        return maxProfitOfRange(prices,0, prices.size());
    }
};
