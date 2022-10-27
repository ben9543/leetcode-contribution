class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, {}, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int> curr, int index){
        if(index >= nums.size()){
            res.push_back(curr);
            return;
        }
        
        curr.push_back(nums[index]);
        helper(res, nums, curr, index+1);
        curr.pop_back();
        helper(res, nums, curr, index+1);
    }
};