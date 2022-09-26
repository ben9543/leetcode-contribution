class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> hm;
        priority_queue<pair<int, int>> pq;
        
        // store in the hashmap
        for (auto n : nums)
        {
            if(hm.find(n) == hm.end()){
                hm[n] = 1;
            } else {
                hm[n]++;
            }
        }
        
        // 
        for(auto p : hm)
        {
            // freq, num
            pair<int, int> tmp;
            tmp.first = p.second;
            tmp.second = p.first;
            pq.push(tmp);
        }
        while(k){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};