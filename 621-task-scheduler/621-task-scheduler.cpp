class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // Process the most frequent task first
        unordered_map<char, int> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int time = 0;
        
        for(auto t : tasks){
            if(m.find(t) == m.end())
                m[t] = 1;
            else 
                m[t]++;
        }
        
        for(auto p : m){
            pq.push(p.second);
        }
        cout << pq.size() << endl;
        while(!pq.empty() || !q.empty()){
            
            // pair[0] = remaining tasks
            // pair[1] = when available?
            time++;
            
            if(!pq.empty()){
                int count = pq.top() - 1; // Because we are using neg values to implement maxHeap
                pq.pop();
                if(count){ // If count is not zero
                    // [Tasks priority, time the task is available again]
                    pair<int, int> p(count, time + n);
                    q.push(p);
                }
            }
            
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
    }
};