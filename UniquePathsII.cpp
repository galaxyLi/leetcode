class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int> > dp(m, vector<int>(n, 0));
		int i, j;
		bool flag = false;
		for (i = m-1; i >= 0; i--) {
			if (flag) continue;
			if (obstacleGrid[i][n-1] == 1) flag = true;
			else dp[i][n-1] = 1;
		}
		flag = false;
		for (j = n-1; j >= 0; j--) {
			if (flag) continue;
			if (obstacleGrid[m-1][j] == 1) flag = true;
			else dp[m-1][j] = 1;
		}
		for (i = m-2; i >= 0; i--) {
			for (j = n-2; j >= 0; j--) {
				if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
				else {
					int right = (j<n-1) ? dp[i][j+1]:0;
					int down = (i<m-1) ? dp[i+1][j]:0;
					dp[i][j] = right+down;
				}
			}
		}
		return dp[0][0];
    }
};
