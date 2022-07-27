class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. Understanding
        //  Need to apply isAnagram function to all string for each O(n^2)
        //  IsAnagram => O(nlogn)
        // 3. Planning (How to make the performance better)
        
        vector<vector<string>> res;
        unordered_map<string, vector<string>> seen;
        for (int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(seen.find(s) == seen.end()){
                vector<string> tmp = {strs[i]};
                seen[s] = tmp;
            } else { // if found
                seen[s].push_back(strs[i]);
            }
        }
        
        // Pushing the results
        for(auto p : seen)
            res.push_back(p.second);
        
        return res;
    }
};