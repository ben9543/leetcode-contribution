class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(DFS(board, word, i, j, 0))return true;
            }
        }
        
        return false;
        
    }
    
    bool DFS(vector<vector<char>>& board, string word, int row, int col, int curr){
        
        // Found
        if(curr >= word.length())return true;
        
        // Out of bound
        if(row >= board.size() || col >= board[0].size() || row < 0 || col < 0)return false;
        
        // Wrong character
        if(board[row][col] != word[curr])return false;
        
        // Do not visit again
        char c = board[row][col];
        board[row][col] = '.';
        
        // Search
        if ( 
            DFS(board, word, row-1, col, curr+1) ||
            DFS(board, word, row+1, col, curr+1) ||
            DFS(board, word, row, col+1, curr+1) ||
            DFS(board, word, row, col-1, curr+1)
        ) return true;
        
        // Backtrack
        board[row][col] = c;
        
        return false;
    }
};