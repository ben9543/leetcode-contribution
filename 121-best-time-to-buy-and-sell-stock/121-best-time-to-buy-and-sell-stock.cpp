class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0; // Should be less
        int sell = 0; // Should be big
        int maxP = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            // Greedy
            if(prices[buy] > prices[i]) buy = i;
            if(prices[sell] < prices[i]) sell = i;
            // Update sell if it is less than buy (cannot sell before buy it.)
            if(sell < buy)sell = buy;
            maxP = max(maxP, prices[sell] - prices[buy]);
        }
        return maxP;
    }
};