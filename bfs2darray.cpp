/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void createMatrix(vector<vector<int>>& m, int row, int col){
    for (int i = 0; i < row; i++){
        vector<int> temp;
        for (int j = 0; j < col; j++){
            temp.push_back(0);
        }
        m.push_back(temp);
    }
}

void createSeen(vector<vector<bool>>& seen, int row, int col){
    for (int i = 0; i < row; i++){
        vector<bool> temp;
        for (int j = 0; j < col; j++){
            temp.push_back(false);
        }
        seen.push_back(temp);
    }
}

void BFS(vector<vector<int>>matrix, queue<vector<int>>& q, vector<vector<bool>>& seen, vector<int>& values)
    {
    
    // 1. Input validation
    while(!q.empty()){        
        vector<int> currPos = q.front();
        q.pop();
        int row = currPos[0];
        int col = currPos[1];
        if ( 
        row < 0 ||row >= matrix.size() ||
        col < 0 ||col >= matrix[0].size() || seen[row][col] )
        {
            continue;
        }
        
        // 2. Update values and seen
        seen[row][col] = true;
        values.push_back(matrix[row][col]);
        
        // 3. Scanning all directions
        
        // 3-1. Create positions
        vector<int> up = {row+1, col};
        vector<int> down = {row-1, col};
        vector<int> right = {row, col+1};
        vector<int> left = {row, col-1};
        
        // 3-2. Push positions to the queue
        q.push(up);
        q.push(down);
        q.push(right);
        q.push(left);
    }
}


int main()
{
    
    vector<vector<int>> matrix = {{1,2,3,4,5,6}, {11,12,13,14,15,16}, {21,22,23,24,25,26}, {31,32,33,34,35,36}, {41,42,43,44,45,46}, {51,52,53,54,55,56}};
    queue<vector<int>> q;
    vector<int> startPos = {0,0};
    q.push(startPos);
    
    vector<vector<bool>> seen;
    vector<int> values;
    
    //createMatrix(matrix, row, col);
    createSeen(seen, matrix.size(), matrix[0].size());
    BFS(matrix, q, seen, values);
    
    for (auto v: values)cout << v << "\t";
    
    return 0;
}
