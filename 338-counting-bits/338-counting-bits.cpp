class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        vector<int> res;
        int offset = 1; // Stores the highest value of the power of 2
        
        for (int i = 1; i < n+1; i++)
        {
            // Update offset whenever we found i that is power of 2
            if(offset * 2 == i)
                offset = i;
            
            // We are getting the number of bits of dp[i] by using the previous results
            // Offset means the most significant bit's value
            dp[i] = 1 + dp[i - offset];
        }
        
        return dp;
    }
};