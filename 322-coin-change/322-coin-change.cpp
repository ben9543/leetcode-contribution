class Solution {
public:
    
    vector<int> dp;
    int MAX_AMOUNT;
    
    int coinChange(vector<int>& coins, int amount) {
        MAX_AMOUNT = amount + 1;
        dp = vector(MAX_AMOUNT, MAX_AMOUNT);
        dp[0] = 0;
        
        for(int a = 1; a <= amount; a++)
        {
            for(auto c : coins)
            {
                if(a-c >= 0)
                    dp[a] = min(dp[a], dp[a-c] + 1);
            }
        }
        
        return (dp[amount] == MAX_AMOUNT) ? -1 : dp[amount];
         
    }
};