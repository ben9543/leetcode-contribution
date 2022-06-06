class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> r(nums.size()+1);
        for (auto num: nums)
            r[num] = true;
        
        for (int i = 0; i < r.size(); i++)
            if (!r[i]) return i;
        
        return nums.size();
    }
};