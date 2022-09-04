class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // 1. Brute force => O(n^2)
        //      - Check each row
        //      - Check each col
        //      - Check each box
        
        // Check each row
        for(int i = 0; i < board.size(); i++)
        {
            unordered_set<char> us;
            for(int j = 0; j < board[0].size(); j++)
            {
                char cell = board[i][j];                
                if(board[i][j] == '.')
                    continue;
                if(us.find(cell) != us.end()){
                    return false;
                } else {
                    us.insert(cell);
                }
            }
        }
        
        cout << "Passed row" << endl;
        
        // Check each col
        for(int i = 0; i < board[0].size(); i++)
        {
            unordered_set<char> us;
            for(int j = 0; j < board.size(); j++)
            {
                char cell = board[j][i];
                if(board[j][i] == '.')
                    continue;
                if(us.find(cell) != us.end()){
                    return false;
                } else {
                    us.insert(cell);
                }
            }
        }
        
        cout << "Passed col" << endl;
        
        // Check subbox
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int row = (i+1) + (i * 2);
                int col = (j+1) + (j * 2);
                if(!checkBox(board, row, col))
                    return false;
            }
        }
        
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board, int row, int col){
        
        unordered_set<char> us;
        for(int i = row-1; i <= row+1; i++)
        {
            for(int j = col-1; j <= col+1; j++)
            {
                //cout << board[i][j] << "\t";
                if(board[i][j] == '.')
                    continue;
                if(us.find(board[i][j]) != us.end())
                    return false;
                else
                    us.insert(board[i][j]);
            }
            //cout << endl;
        }
        //cout << endl;
        return true;
    }
};