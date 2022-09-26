class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result = {};
        vector<vector<int>> res(nums.size()+1);
        unordered_map<int, int> hm;
        
        // nO(logn) => Sort
        // O(n) => Bucket Sort
        
        if(nums.size() == k)return nums;
        
        // Get frequencies
        for(auto n : nums){
            if(hm.find(n) == hm.end())
                hm[n] = 1;
            else
                hm[n]++;
        }
        
        // We are storing a count as index. Each index will have a vector of integers.
        for(auto p : hm){
            int freq = p.second;
            int key = p.first;
            res[freq].push_back(key);
        }
        
        // Appending to the result
        for(int i = res.size()-1; i >= 0; i--){
            if(res[i].empty())continue;
            for(auto r : res[i]){
                
                // Push elements
                result.push_back(r);
                
                // It is guaranteed that we are going to find the answer
                if(result.size() == k)return result;
            }
        }
        
        return result;
    }
};