#include<map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> seen;
        for(int i = 0; i < nums.size(); i++){
            if(seen.count(nums[i])){
                return true;
            } else {
                seen[nums[i]] = true;
            }
        }
        return false;
    }
};