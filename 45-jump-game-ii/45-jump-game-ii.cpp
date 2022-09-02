class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()==1) return 0;
        
        int jumpCount = 0;
        int left = 0;
        int right = 0;
        
        // Update left as right + 1
        // Update right as the maximum jump from the range
    
        while(right < nums.size()-1)
        {
            int farthest = 0;
            for (int i = left; i <= right; i++)
            {
                farthest = max(farthest, nums[i] + i);
            }
            left = right+1;
            right = farthest;
            jumpCount++;
        }
        
        return jumpCount;
    }
};