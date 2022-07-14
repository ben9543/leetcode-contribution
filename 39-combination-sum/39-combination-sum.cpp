#include <map>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 1. Understanding
        //      - Distinct elements
        //      - Return unique combinations
        //      - Edge cases: When candidates length is 1
        //      - Questions: Is array sorted?
        // 2. Matching
        //      - Possible solution can be: Sort = Binary search 
        //      
        // 3. Planning
        //     - Brute force: 1) Add until the sum reaches to the target number => Need to try every possible cases: Dynamic programming
        // Things to consider: [3,5] [5,3] is not allowed => How to find out those two are the same? we can just sort the array
        // Can use candidates as much as I want
        // 1) keep adding a candidate until it reaches or excceeds the target value [2,2,2,2] ,target = 7
        // 2) If the sum is not the same as the target value and exceeds it, backtrack [2,2,2], target = 7
        // 3) Check the difference between the sum and the target is still too small 7 - 6 = 1 and we don't have 1 as a candidate
        // 4) Subtract the current candidate again [2,2], target = 7
        // 5) Check the difference between the sum and the target is still too small 7 - 4 = 3 and it is bigger than the current candidate
        // 6) Move on to the next candidate 
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        
        for (int i = 0; i < candidates.size(); i++){
            vector<int> temp;
            if(candidates[i] < target) dp(0, i, target, temp, candidates, res);
            else if(candidates[i] == target) res.push_back(vector<int>(1, candidates[i]));
        }
        
        return res;
    }
    void dp(int sum, int index, int target, vector<int> temp, vector<int> candidates, vector<vector<int>>& res){
        sum += candidates[index];
        temp.push_back(candidates[index]);
        if(sum == target) res.push_back(temp);
        else if(sum < target){
            for (int i = index; i < candidates.size(); i++){
                if(sum+candidates[i] <= target)
                    dp(sum, i, target, temp, candidates, res);
            }
        }
    }
};