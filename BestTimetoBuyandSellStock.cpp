class Solution {
public:
    int maxProfit(vector<int> &prices) {
        size_t n = prices.size();
        if (n < 2) return 0;
        size_t i;
        int min_v, max_v;
        min_v = prices[0];
        max_v = 0;
        for (i = 1; i < n; i++) {
            int tmp;
            if (prices[i] < min_v) {
                min_v = prices[i];
            } else {
                tmp = prices[i] - min_v;
                max_v = max(tmp, max_v);
            }
        }
        return max_v;
    }
};
