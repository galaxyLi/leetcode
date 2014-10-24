class Solution {
public:
    void swap(int &a, int &b) {
        a = a+b;
        b = a-b;
        a = a-b;
    }
    void rotate(vector<vector<int> > &matrix) {
        int i, j, n;
        n = matrix.size();
        for (i = 0; i <= n/2; i++) {
            for (j = i; j < n-i-1; j++) {
                swap(matrix[i][j], matrix[n-j-1][i]);
                swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
                swap(matrix[n-i-1][n-j-1], matrix[j][n-i-1]);
            }
        }
    }
};
