#include<map>
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> seen(nums.size()+1, 0);
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            seen[nums[i]]+=1;
        }
        for (int i = 1; i <= nums.size(); i++){
            if(seen[i] == 0) res.push_back(i);
        }
        return res;
    }
};