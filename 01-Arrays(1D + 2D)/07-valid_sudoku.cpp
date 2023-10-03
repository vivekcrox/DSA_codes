class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int val){
        int n = board.size();
        for(int i=0; i<n; i++){
            // row check
            if(board[row][i] == val)
                return false;
            
            // col check
            if(board[i][col] == val)
                return false;
            
            // 3x3 sub-matrix check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
                return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                char val = '.';
                if(board[i][j] != '.'){
                    val = board[i][j];
                    board[i][j] = '.';
                    bool ans = isSafe(board, i, j, val);
                    if(ans == false)
                        return false;
                }
                board[i][j] = val;
            }
        }
        return true;
    }
};
