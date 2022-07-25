#include <algorithm>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = 0;
        for (int i = 1; i < nums.size(); i++){
            if(nums[j] == nums[i])return nums[j];
            j++;
        }
        return -1;
    }
};