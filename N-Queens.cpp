class Solution {
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

	void solve(vector<vector<string> > &ans, vector<int> &pos, bool **vis, int n, int row) {
		for (int i = 0; i < n; i++) {
			if (can_place(vis, n, row, i)) {
				vis[row][i] = true;
				pos.push_back(i);
				if (row == n-1) {
					vector<string> tmp;
					for (int j = 0; j < n; j++) {
						string str;
						for (int k = 0; k < n; k++) {
							if (k == pos[j]) str += "Q";
							else str += ".";
						}
						tmp.push_back(str);
					}
					ans.push_back(tmp);
				} else {
					solve(ans, pos, vis, n, row+1);
				}
				vis[row][i] = false;
				pos.pop_back();
			}
		}
	}

    vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > ans;
		if (n == 1) {
			string str("Q");
			vector<string> tmp;
			tmp.push_back(str);
			ans.push_back(tmp);
			return ans;
		}
		if (n < 4) return ans;
		vector<int> pos;
		bool **vis = new bool*[n];
		for (int i = 0; i < n; i++) vis[i] = new bool[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) vis[i][j] = false;
        solve(ans, pos, vis, n, 0);
		return ans;
    }
};
