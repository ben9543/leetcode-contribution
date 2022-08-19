class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if you end up being on 0, the path is not valid
        // Brute force
        // Try all possible jumps
        
        // Linear way
        // Find 0
        // Calculate the maximum jump so far
    
        if(nums.size() == 1)return true;
        if(nums[0] == 0)return false;
        
        int m = nums[0];
        
        // Don't need to check the last element (nums.size()-1)
        for(int i = 0; i < nums.size()-1; i++)
        {
            int n = nums[i];
            m = max(m, n);
            if(n == 0){
                if(m == 0){
                    return false;  
                }
            }
            m--;
        }
        return true;
    }
};