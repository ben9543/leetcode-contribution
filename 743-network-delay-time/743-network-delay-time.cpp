class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int,int>>());
        int res = 0;
        unordered_set<int> visited;
        
        // Creating adjacency list
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            adj[source].push_back({time, dest});
        }
        
        // Want to visit smaller weighted edges first
        // Need to use minHeap
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
        minHeap.push({0,k});
        
        while(!minHeap.empty()){
            int elapsedTime = minHeap.top().first;
            int currNode = minHeap.top().second;
            minHeap.pop();
            
            // If the node is already visited, ignore
            if(visited.find(currNode) != visited.end())continue;
            
            // Mark visited nodes
            visited.insert(currNode);
            
            // Upate the max
            res = max(res, elapsedTime);
            
            // Push all attached nodes the minheap with updated time 
            for(auto p : adj[currNode]){
                minHeap.push({p.first+elapsedTime, p.second});
            }
        }
        
        // Return res if we visited all nodes. Else return -1.
        return (visited.size() == n) ? res : -1;
    }
};
