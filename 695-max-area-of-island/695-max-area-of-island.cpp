class Solution {
public:
    int maxArea = 0;
    vector<pair<int, int>> dir = {
            {0,-1},     // Up
            {0, 1},     // Down
            {-1, 0},    // Left
            {1, 0}      // Right
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                    maxArea = max(maxArea, BFS(grid, i, j));
            }
        }
        return maxArea;
    }
    
    int BFS(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        if(grid[i][j]==0)return 0;
        
        int area = 1;
        grid[i][j] = 0;
        
        for(auto p : dir)
        {
            area+=BFS(grid, i+p.first, j+p.second);
        }
        return area;
    }
};