#include <queue>
#include <vector>
class Solution {
public:
    static vector<vector<int>> dir;
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        // 1. Need to use BFS instead of DFS. There may be initial rotten orange more than one. 
        // 2. Loop through the grid, put rotten oranges location into the queue.
        // 3. Pop the queue, make all oranges adjacent rotten, then push the grids
        
        int minutes = 0;
        int freshOranges = 0;
        queue<vector<int>> q;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){\
                if(grid[i][j] == 2){
                    vector<int> tmp = {i, j};
                    q.push(tmp);
                } else if(grid[i][j] == 1) {
                    freshOranges += 1;
                }
            }
        }
        
        // freshOranges > 0 will help the program to break the loop when there is no fresh oranges 
        // so that we don't add additional minute at the end of the loop.
        while(!q.empty() && freshOranges > 0){
            int l = q.size();
            
            // Process items only in the current at this point 
            while(l){
                vector<int> i = q.front();
                q.pop();
                for(auto d: dir){
                
                    int row = i[0] + d[0];
                    int col = i[1] + d[1];

                    // Handle out of bounds && 0 & 2
                    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || grid[row][col] == 2)
                        continue;
                    else {

                        // Make it rotten
                        grid[row][col] = 2;
                        freshOranges--;

                        // Push new grids
                        vector<int> tmp = {row,col};
                        q.push(tmp);
                    }
                }
                l--;
            }
            
            // After process the queue, increase the minute
            minutes++;
            // printGrid(grid);
        }
        if(freshOranges > 0)return -1;
        else return minutes;
    }
    
    static void printGrid(vector<vector<int>> grid){
        for (auto v: grid){
            for (auto i: v){
                cout << i << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
};

vector<vector<int>> Solution::dir = {
        //   row col
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };