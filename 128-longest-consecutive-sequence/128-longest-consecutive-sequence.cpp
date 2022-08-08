class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        vector<int> res;
        int maxCount = 1;
        
        if(nums.size() == 0)return 0;
        
        // Create the set
        for(auto n : nums)s.insert(n);
        
        for(auto n : nums){
            
            // If n-1 is not found in the set, n is the first element of the seq
            int l = 0;
            if(s.find(n-1) == s.end()){
                
                // Increase the length until n+l does not exists in the set (found last element of the seq)
                while(s.find(n+l) != s.end())l++;
            }
            maxCount = max(maxCount, l);
        }
        return maxCount;
    }
};