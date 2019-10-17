class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minPrice = INT_MAX;
        int maxPriceAfterBuy = INT_MAX;
        int profit = 0;
        
        for(int i=0;i<len;i++){
            if(prices[i] < maxPriceAfterBuy){
                profit += maxPriceAfterBuy-minPrice;
                minPrice = prices[i];
                maxPriceAfterBuy = prices[i];
            }else {
                maxPriceAfterBuy = max(maxPriceAfterBuy,prices[i]);
            }
        }
        profit += maxPriceAfterBuy-minPrice;
        
        return profit;
    }
};
