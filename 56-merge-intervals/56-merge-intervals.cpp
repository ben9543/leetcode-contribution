class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        // Sort
        sort(intervals.begin(), intervals.end());
        
        for (auto i : intervals){
            if (res.empty()){
                res.push_back(i);
            } else {
                if(res[res.size()-1][1] >= i[0]){
                    vector<int> newInterval = {res[res.size()-1][0], max(res[res.size()-1][1], i[1])};
                    res[res.size()-1] = newInterval;
                } else {
                    res.push_back(i);
                }
            }
        }
        
        
        return res;
    }
};