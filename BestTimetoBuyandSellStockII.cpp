class Solution {
public:
    int maxProfit(vector<int> &prices) {
        size_t n = prices.size();
        if (n < 2) return 0;
        size_t i;
        int ans = 0;
        for (i = 1; i < n; i++) {
            int tmp = prices[i] - prices[i-1];
            if (tmp > 0) ans += tmp;
        }
        return ans;
    }
};
