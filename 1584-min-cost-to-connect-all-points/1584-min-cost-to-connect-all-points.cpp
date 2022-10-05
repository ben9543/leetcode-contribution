class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // MST
        // Prim's Algorithm
        unordered_set<int> visited;
        vector<vector<pair<int, int>>> adj(points.size()+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                if(i == j)continue;
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({cost, j});
            }
        }
        
        minHeap.push({0,0});
        int res = 0;
        while(!minHeap.empty())
        {
            int currNode = minHeap.top().second;
            int currCost = minHeap.top().first;
            minHeap.pop();
            if(visited.find(currNode) != visited.end())continue;
            res += currCost;
            visited.insert(currNode);
            //if(visited.size() == points.size())break;
            for(int i = 0; i < adj[currNode].size(); i++){
                
                int nextNode = adj[currNode][i].second;
                int nextCost = adj[currNode][i].first;
                
                minHeap.push({nextCost, nextNode});
            }
        }
        
        return res;
    }
};