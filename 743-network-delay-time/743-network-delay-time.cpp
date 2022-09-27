class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // 0: weight
        // 1: destination
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto t : times)
        {
            int source = t[0];
            int dest = t[1];
            int time = t[2];
            adj[source].push_back({time, dest});
        }
        
        // Keep track of minimum time of receiving signal from node k
        vector<int> recvTimes(n + 1, INT_MAX);
        recvTimes[k] = 0;
        
        // Minheap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int currNode = pq.top().second;
            int currTime = pq.top().first;
            pq.pop();
            if (currTime > recvTimes[currNode]) 
                continue;
            
            for(auto item : adj[currNode]){
                if(recvTimes[item.second] > currTime+item.first){
                    recvTimes[item.second] = currTime+item.first;
                    pq.push({currTime+item.first, item.second});
                }
            }
            
        }
        
        int result = INT_MIN;
        
        for (int i = 1; i <= n; i++){
            result = max(recvTimes[i], result);
        }
        
        return (result==INT_MAX) ? -1 : result;
    }
};

