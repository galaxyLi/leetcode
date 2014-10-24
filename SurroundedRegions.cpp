class Solution {
public:
    void bfs(vector<vector<char> > &board, int row, int colum) {
    	if (board[row][colum] == 'X') return;
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int> > q;
        board[row][colum] = 'V';
        q.push(make_pair(row, colum));
        while (!q.empty()) {
            pair<int, int> tp = q.front();
            q.pop();
            int i = tp.first;
            int j = tp.second;
            if (i > 0) {
                if (board[i-1][j]=='O') {
                    board[i-1][j] = 'V';
                    q.push(make_pair(i-1, j));
                }
            }
            if (i < m-1) {
                if (board[i+1][j]=='O') {
                    board[i+1][j] = 'V';
                    q.push(make_pair(i+1, j));
                }
            }
            if (j > 0) {
                if (board[i][j-1]=='O') {
                    board[i][j-1] = 'V';
                    q.push(make_pair(i, j-1));
                }
            }
        	if (j < n-1) {
                if (board[i][j+1]=='O') {
                    board[i][j+1] = 'V';;
                    q.push(make_pair(i, j+1));
                }
            }
        }
    }
    void solve(vector<vector<char> > &board) {
        int m = board.size();
        if (m < 3) return;
        int n = board[0].size();
        int i, j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (i==0 || j==0 || i==m-1 || j==n-1) bfs(board, i, j);
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == 'V') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
