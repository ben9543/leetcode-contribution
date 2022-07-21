#include<algorithm>
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recurPermute(0,nums,res);
            return res;
        // The idea of the solution
        // Form all possible combinations by swaping elements with the given index.
        // index: 0 [1,2,3,4] => [2,1,3,4] => [3,2,1,4] => [4,2,3,1]
        // Increase the index and try the same process with the combinations we just created.
        
    }
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &res){
        
        // When index is out of the range, the current nums is unique.
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        
        // Starting from the index.
        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            recurPermute(index+1, nums, res);
            // Swap it back
            swap(nums[index], nums[i]);
        }
    }
};


/*
class Solution {
    public:
    void recurPermute(int index,vector<int> &nums,vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            recurPermute(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
        
        
    }
    
    
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0,nums,ans);
            return ans;
    }
};
*/