class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool row = false;
        bool colum = false;
        size_t m, n;
        m = matrix.size();
        n = matrix[0].size();
        /* check row 0 */
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                row = true;
                break;
            }
        }
        /* check colum 0 */
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                colum = true;
                break;
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
        	for (int j = 1; j < n; ++j) {
        		if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        	}
        }
        if (row)
        	for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        if (colum)
        	for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};
