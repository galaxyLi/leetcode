class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const size_t n = prices.size();
        if (n < 2) return 0;
        vector<int> f(n, 0);
        vector<int> g(n, 0);
        
        for (int i = 1, valley = prices[0]; i < n; ++i) {
            valley = min(valley, prices[i]);
            f[i] = max(f[i-1], prices[i]-valley);
        }
        
        for (int i = n-2, peak = prices[n-1]; i >= 0; --i) {
            peak = max(peak, prices[i]);
            g[i] = max(g[i+1], peak-prices[i]);
        }
        
        int max_profit = 0;
        for (int i = 0; i < n; ++i) {
            max_profit = max(max_profit, f[i]+g[i]);
        }
        return max_profit;
    }
};
