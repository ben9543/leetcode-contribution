class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> um;
        return helper(nums, 0 , 0, um);
    }
    
    int helper(vector<int>& nums, int sum, int n, unordered_map<int, int>& um){
        // Two cases:
        
        if(n >= nums.size())return sum;
        
        // n+1 vs helper(n+2)
        if(um.find(n) != um.end())
            return sum+um[n];
        else
            return um[n] = max(helper(nums, sum, n+1, um), helper(nums, sum+nums[n], n+2, um));
    }
};