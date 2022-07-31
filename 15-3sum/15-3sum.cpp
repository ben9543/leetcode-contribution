class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        
        // Sort the array first. This is for removing duplicates & two pointer search.
        sort(nums.begin(), nums.end());
    
        for(int i = 0; i < nums.size(); i++)
        {
            
            // Skipping i
            if(i > 0 && nums[i-1] == nums[i])continue;
            
            int aptr = i+1;
            int bptr = nums.size()-1;
            while(aptr < bptr)
            {
                int sum = nums[i] + nums[aptr] + nums[bptr];
                if(sum == 0){
                    vector<int> tmp = {nums[i], nums[aptr], nums[bptr]};
                    res.push_back(tmp);
                    
                    // Skipping duplicates
                    aptr++;
                    while(nums[aptr-1] == nums[aptr] && aptr < bptr)
                        aptr++;
                    
                } else if(sum < 0) {
                    aptr++;
                } else {
                    bptr--;
                }
            }
        }
        
        return res;
    }
};