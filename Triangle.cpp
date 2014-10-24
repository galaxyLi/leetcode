class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            int i, j, len = triangle.size();
            int *sum = new int[len];
            for (i = 0; i < len; i++) sum[i] = triangle[len-1][i];
            for (i = len-2; i >= 0; i--)
                for (j = 0; j < triangle[i].size(); j++)
                    sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);

            return sum[0];
        }
};
