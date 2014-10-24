class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
		vector<vector<int> > dp(m, vector<int>(n, 0));
		int i, j;
		for (i = 0; i < m; i++) dp[i][n-1] = 1;
		for (j = 0; j < n; j++) dp[m-1][j] = 1;
		for (i = m-2; i >= 0; i--) {
			for (j = n-2; j >= 0; j--) {
				int right = (j<n-1) ? dp[i][j+1]:0;
				int down = (i<m-1) ? dp[i+1][j]:0;
				dp[i][j] = right+down;
			}
		}
		return dp[0][0];
    }
};
