class Solution {
public:
    
    vector<int> dp;
    
    int coinChange(vector<int>& coins, int amount) {
        // 1. Understanding
        //  Coins can be reused
        //  There could be no answer 
        
        // 2. Matching
        //  Dynamic Programming => Because "fewest"
        
        // 3. Planning
        //  By subtracting each coin until the amount gets to zero. 
        //  We need to update the return value by finding the fewest num of coins we used.
        // dp[i] represents amount of coins used to get i
        
        
        // Construct DP
        dp = vector<int> (amount+1, amount+1);
        dp[0] = 0;
        for(int a = 1; a <= amount; a++){
            for(int j = 0; j < coins.size(); j++){
                
                // Can be a valid answer
                if(a - coins[j] >= 0){
                    dp[a] = min(dp[a], 1 + dp[a - coins[j]]);
                }
            }
        }
        
        return dp[amount] != amount+1 ? dp[amount] : -1;
    }

};