class Solution {
public:
    bool dfs(vector<vector<char> > &board, string &word, vector<vector<bool> > &vis, int k, int row, int colum) {
		int len = word.size();
		if (k == len-1) return true;
		int m = board.size();
		int n = board[0].size();
		int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
		for (int i = 0; i < 4; i++) {
			int first = row+dir[i][0];
			int second = colum+dir[i][1];
			if ((0<=first && first<m) && (0<=second && second<n)) {
				if (!vis[first][second] && board[first][second] == word[k+1]) {
					vis[first][second] = true;
					if (dfs(board, word, vis, k+1, first, second)) return true;
					vis[first][second] = false;
				}
			}
		}
		return false;
	}
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty()) return true;
		if (board.empty()) return false;
		int m = board.size();
		int n = board[0].size();
		int len = word.size();
		int i, j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (board[i][j] == word[0]) {
					vector<vector<bool> > vis(m, vector<bool>(n, false));
					vis[i][j] = true;
					if (dfs(board, word, vis, 0, i, j)) return true;
				}
			}
		}
		return false;
    }
};
