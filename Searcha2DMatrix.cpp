class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i, j;
        for (i = 0; i < m; i++) {
            for (j = n-1; j >= 0; j--) {
                if (target == matrix[i][j]) return true;
                else if (target > matrix[i][j]) {
                    if (j == n-1) break;
                    else return false;
                } else {
                    if (j == 0) return false;
                }
            }
        }
        return false;
    }
};
