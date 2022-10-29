class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Base case: If the current sum exceeds the target, return
        // If the current sum becomes same as the target, push and return
        vector<vector<int>> res;
        
        // Either take the current or the next
        helper(candidates, res, target, {}, 0, 0);
        return res;
    }
    
    void helper(vector<int>& candidates, vector<vector<int>>& res, int target, vector<int> curr, int sum, int index){
        if(index >= candidates.size()) return;
        if(sum > target) return;
        if(sum == target){
            res.push_back(curr);
            return;
        }
        
        sum+=candidates[index];
        curr.push_back(candidates[index]);
        helper(candidates, res, target, curr, sum, index);
        sum-=candidates[index];
        curr.pop_back();
        helper(candidates, res, target, curr, sum, index+1);
    }
};