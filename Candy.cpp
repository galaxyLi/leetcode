class Solution {
public:
    int candy(vector<int> &ratings) {
        size_t n = ratings.size();
        if (n == 0) return 0;
        vector<int> v(n, 0);
        int i;
        for (i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                v[i] = max(v[i], v[i-1]+1);
            }
        }
        for (i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                v[i] = max(v[i], v[i+1]+1);
            }
        }
        int sum = n;
        for (i = 0; i < n; i++) sum += v[i];
        return sum;
    }
};
