class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int m = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++){
            sum = max(sum + nums[i], nums[i]);
            m = max(sum, m);
            
        }
        return m;
    }
};