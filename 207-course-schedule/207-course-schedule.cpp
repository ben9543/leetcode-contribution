class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Create an adjcency list
        unordered_map<int, vector<int>> adj;
        unordered_set<int> visited;
        for (auto p : prerequisites)
        {
            // p[0] => Course want to take
            // p[1] => Prerequisites
            
            adj[p[0]].push_back(p[1]);
        }
        
        for(int i = 0; i < numCourses; i++){
            
            if(!DFS(adj, visited, i))return false;
        }
    
        return true;
    }
    
    bool DFS(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, int curr){
        if(visited.find(curr) != visited.end()) return false;
        if(adj[curr].empty())return true;
        visited.insert(curr);
        for(auto el : adj[curr])
            if(!DFS(adj, visited, el))return false;
        
        // Remove the curr course from the visited after DFS.
        // The curr cannot be ignored, we finished its prerequsites, not the course itself yet.
        visited.erase(curr);
        
        // Set it to the empty list because we finined all prerequsites of this course
        // and now we can take this course
        adj[curr] = {};
        return true;
    }
    
};