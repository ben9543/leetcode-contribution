class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // 1. Count number of tasks
        unordered_map<char, int> cnt;
        for(auto c : tasks){
            if(cnt.find(c) == cnt.end())
                cnt[c] = 1;
            else
                cnt[c]++;
        }
        
        // 2. Push the tasks to the priority queue
        // pair structure: <num of left tasks, available time>
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(auto t : cnt){
            pq.push(t.second);
        }
        
        // 3. Process the priroity queue
        // We will use a queue to hold processing tasks until the first element of the queue will be available
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int task = pq.top();
                pq.pop();
                if(task-1 > 0)q.push({task-1, time+n});
            }
            if(!q.empty()){
                auto task = q.front();
                if(task.second <= time){
                    q.pop();
                    pq.push(task.first);
                }
            }
        }
        
        return time;
    }
};