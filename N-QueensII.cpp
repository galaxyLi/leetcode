class Solution {
public:
public:
	bool can_place(bool **vis, int n, int row, int colum) {
		int i, j;
		/* 检查列 */
		for (i = row; i >= 0; i--) {
			if (vis[i][colum]) return false;
		}
		/* 检查对角线 */
		for (i = 0; i < row; i++) {
			for (j = 0; j < n; j++) {
				if (abs(i-row)==abs(j-colum) && vis[i][j]) return false;
			}
		}
		return true;
	}

	void solve(int &ans, bool **vis, int n, int row) {
		for (int i = 0; i < n; i++) {
			if (can_place(vis, n, row, i)) {
				vis[row][i] = true;
				if (row == n-1) ans++;
				else solve(ans, vis, n, row+1);
				vis[row][i] = false;
			}
		}
	}

    int totalNQueens(int n) {
		if (n == 1) return 1;
		if (n < 4) return 0;
		bool **vis = new bool*[n];
		for (int i = 0; i < n; i++) vis[i] = new bool[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) vis[i][j] = false;
		int ans = 0;
        solve(ans, vis, n, 0);
		return ans;
    }
};
