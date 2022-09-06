class Solution {
public:
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for(int i = 0; i < nums.size(); i++)
        {
            vector<int> tmp = {nums[i]};
            res.push_back(tmp);
            helper(res, nums, tmp, i+1);
        }
        return res;
    }
    
    void helper(vector<vector<int>>&res, vector<int>& nums, vector<int>tmp, int i){
        // Either take or not
        if(i >= nums.size())return;
        
        tmp.push_back(nums[i]);
        res.push_back(tmp);
        helper(res, nums, tmp, i+1);
        tmp.erase(tmp.end()-1);
        helper(res, nums, tmp, i+1);
    }
};