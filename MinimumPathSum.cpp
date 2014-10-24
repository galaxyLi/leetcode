class Solution {
public:
	int bfs(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dis(m, vector<int>(n, 0x7fffffff));
        queue<pair<int, int> > q;
        dis[0][0] = grid[0][0];
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            pair<int, int> tp = q.front();
            q.pop();
            int i = tp.first;
            int j = tp.second;
            if (i < m-1) {
                if (dis[i+1][j] == 0x7fffffff) {
                	dis[i+1][j] = dis[i][j]+grid[i+1][j];
                    q.push(make_pair(i+1, j));
                } else {
                    int sum = dis[i][j]+grid[i+1][j];
                    if (sum < dis[i+1][j]) {
                        dis[i+1][j] = sum;
                        q.push(make_pair(i+1, j));
                    }
                }
            }
            if (j < n-1) {
                if (dis[i][j+1] == 0x7fffffff) {
                    dis[i][j+1] = dis[i][j]+grid[i][j+1];
                    q.push(make_pair(i, j+1));
                } else {
                    int sum = dis[i][j]+grid[i][j+1];
                    if (sum < dis[i][j+1]) {
                        dis[i][j+1] = sum;
                        q.push(make_pair(i, j+1));
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return 0;
        return bfs(grid);
    }
};
