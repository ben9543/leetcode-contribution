#include<algorithm>
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int> nums, int curr){
        if(curr == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i = curr; i < nums.size(); i++){
            swap(nums[curr], nums[i]);
            helper(res, nums, curr+1);
            swap(nums[curr], nums[i]);
        }
    }
}; 