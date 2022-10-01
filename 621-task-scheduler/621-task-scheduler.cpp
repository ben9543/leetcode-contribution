class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        unordered_map<char, int> cnt;
        
        // Counting tasks
        for(auto c : tasks){
            if(cnt.find(c) == cnt.end())cnt[c] = 1;
            else cnt[c]++;
        }
        for(auto item : cnt){
            pq.push(item.second);
        }
        
        while(!pq.empty() || !q.empty()){
            
            // Increase the time
            time++;
            
            // Process it and push it to queue
            if(!pq.empty()){
                int freq = pq.top()-1;
                pq.pop();
                if(freq > 0)
                    q.push({freq, time+n});
            }
            
            // Push it back to pq if the number of tasks is not zero & the time aligns
            if(!q.empty()){
                if(q.front().second <= time){
                    pq.push(q.front().first);
                    q.pop();
                }
            }            
        }
        
        
        return time;
    }
};