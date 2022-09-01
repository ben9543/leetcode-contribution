class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> res;
        helper(res, candidates, target, {}, 0, 0);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int> curr, int i, int total){
        if(total > target || i >= candidates.size()) return;
        if(total == target){
            res.push_back(curr);
            return;
        }
        curr.push_back(candidates[i]);
        helper(res, candidates, target, curr, i, total+candidates[i]);
        curr.erase(curr.end()-1);
        helper(res, candidates, target, curr, i+1, total);
    }
};