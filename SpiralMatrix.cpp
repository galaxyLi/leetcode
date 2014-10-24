class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;
        int i, j;
        int m = matrix.size();
        int n = matrix[0].size();
        bool vis[m][n];
        for (i = 0; i < m; i++)
            fill(vis[i], vis[i]+n, false);
        /* check finish or not */
        bool flag;
        i = j = 0;
        while (true) {
            flag = true;
            /* right */
            while (j<n && !vis[i][j]) {
                flag = false;
                vis[i][j] = true;
                ans.push_back(matrix[i][j++]);
            }
            i++;
            j--;
            /* down  */
            while (i<m && !vis[i][j]) {
                flag = false;
                vis[i][j] = true;
                ans.push_back(matrix[i++][j]);
            }
            j--;
            i--;
            /* left  */
            while (j>=0 && !vis[i][j]) {
                flag = false;
                vis[i][j] = true;
                ans.push_back(matrix[i][j--]);
            }
            i--;
            j++;
            /*  up   */
            while (i>=0 && !vis[i][j]) {
                flag = false;
                vis[i][j] = true;
                ans.push_back(matrix[i--][j]);
            }
            j++;
            i++;
            if (flag) break;
        }
        return ans;
    }
};
