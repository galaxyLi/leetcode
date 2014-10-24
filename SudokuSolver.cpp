class Solution {
public:
    bool can_place(vector<vector<char> > &board, int row, int colum, char num) {
        int i, j;
        // check row
        for (i = 0; i < 9; i++)
            if (board[row][i] == num) return false;
        // check colum
        for (i = 0; i < 9; i++)
            if (board[i][colum] == num) return false;
        // check submatrix
        int r = 3*(row/3);
        int c = 3*(colum/3);
        for (i = r; i < r+3; i++)
            for (j = c; j< c+3; j++)
                if (board[i][j] == num) return false;
        return true;
    }

    bool solve(vector<vector<char> > &board, int row, int colum) {
        bool flag = false;
        if (board[row][colum] == '.') {
            for (int i = 1; i <= 9; i++) {
                if (can_place(board, row, colum, char(i+'0'))) {
                    board[row][colum] = char(i+'0');
                    if (row==8 && colum==8) return true;
                    if (colum == 8) flag = solve(board, row+1, 0);
                    else flag = solve(board, row, colum+1);
                	if (flag) return true;
                }
                board[row][colum] = '.';
            }
        } else {
        	if (row==8 && colum==8) return true;
            else if (colum == 8) flag = solve(board, row+1, 0);
            else flag = solve(board, row, colum+1);
        }
        return flag;
    }
        
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0, 0);
    }
};
