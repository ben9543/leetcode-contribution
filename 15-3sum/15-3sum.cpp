class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        
        // Sort the array first. This is for removing duplicates & two pointer search.
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++)
        {
            
            if(i > 0 && nums[i] == nums[i-1])continue;
            
            int low = i +1;
            int high = nums.size() - 1;
            
            while(low < high)
            {
                int sum = nums[low] + nums[high] + nums[i];
                if(sum < 0) low++;
                else if(sum > 0) high--;
                else{
                    vector<int> tmp = {nums[low], nums[high], nums[i]};
                    res.push_back(tmp);
                    low++;
                    while(nums[low] == nums[low-1] && low < high)low++;
                }
            }
        }
        
        return res;
    }
};