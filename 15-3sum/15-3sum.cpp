class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        int i = 0;
        sort(nums.begin(), nums.end());
        
        // Nested for loop + two pointer approach
        while(i < nums.size())
        {
            while(i != 0 && i < nums.size() && nums[i-1] == nums[i])
                i++;
            
            int low = i+1;
            int high = nums.size()-1;
            
            while(low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if(sum < 0){
                    low++;
                } else if(sum > 0) {
                    high--;
                } else {
                    res.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    while(low < high && nums[low-1] == nums[low])
                        low++;
                }
            }
            i++;
        }
        
        return res;
    }
};