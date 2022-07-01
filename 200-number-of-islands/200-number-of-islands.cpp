#include <queue>
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int count = 0;
        
        // Approach: if '1' is found, flip all connected '1's to '0'. Count up islandCount
        
        // row
        for (int i = 0; i < grid.size(); i++){
            
            // col
            for (int j = 0; j < grid[0].size(); j++){
                
                if (grid[i][j] == '1'){
                    count++;
                    grid[i][j] = '0';
                    queue<vector<int>> q;
                    vector<int> currPos = {i,j};
                    q.push(currPos);
                    
                    // Do BFS until there is no connected land
                    while(!q.empty()){
                        // Poll from queue
                        vector<int> el = q.front();
                        q.pop();
                        int row = el[0];
                        int col = el[1];

                        // Scan up, down, left, right
                        vector<int> up = {row+1, col};
                        vector<int> down = {row-1, col};
                        vector<int> left = {row, col-1};
                        vector<int> right = {row, col+1};
                        
                        vector<vector<int>> dir = {up, down, left, right};
                        
                        for (auto v : dir){
                            if(v[0] < 0 || v[0] >= grid.size() || v[1] < 0 || v[1] >= grid[0].size())continue; 
                            cout << v[0] << ":" << v[1] << endl;
                            if(grid[v[0]][v[1]] == '1') {
                                q.push(v);
                                grid[v[0]][v[1]] = '0';
                            }
                        }
                        
                    }
                }
            }
        }
        return count;
    }
};