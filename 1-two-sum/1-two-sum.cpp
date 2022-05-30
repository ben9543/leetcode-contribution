class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int aPtr, bPtr;
        for (int i = 0; i < nums.size()-1; i++){
            int key = target - nums[i];
            
            // Check if key is in nums
            auto pos = find(nums.begin()+i+1, nums.end(), key);
            if (pos!=nums.end()) {
                aPtr = i;
                bPtr = pos - nums.begin();
                break;
            }
        }
        vector<int> r = {aPtr, bPtr};
        return r;
    }
};