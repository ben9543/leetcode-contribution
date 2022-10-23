class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if(DFS(board, word, 0, i, j))return true;
            }
        }
        return false;
    }
    
    bool DFS(vector<vector<char>>& board, string word, int curr, int i, int j){
        if(curr >= word.length())
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[curr] != board[i][j])
            return false;
        
        char tmp = board[i][j];
        board[i][j] = '#';

        if(DFS(board, word, curr+1, i+1, j) || DFS(board, word, curr+1, i-1, j) || DFS(board, word, curr+1, i, j+1) || DFS(board, word, curr+1, i, j-1))
           return true;
        
        board[i][j] = tmp;
        
        return false;
    }
};