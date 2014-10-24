class Solution {
public:
	int minCut(string s) {
    	int i, j, k, len = s.size();
		vector<vector<bool>> dp(len, vector<bool>(len, false));
		for (i = 1; i <= len; i++) {
			for (j = 0; j < len; j++) {
				k = j+i-1;
				k = k>(len-1) ? (len-1):k;
				if (j == k) dp[j][k] = true;
				else if (j+1 == k) dp[j][k] = (s[j]==s[k]);
				else dp[j][k] = (dp[j+1][k-1] && (s[j]==s[k]));
			}
		}
        vector<int> minCuts(len, len-1);
        minCuts[0] = 0;
        for(k = 1; k < len; k++){
            if(dp[0][k]) minCuts[k] = 0;
            for(int p = 0; p < k; p++){
                if(dp[p+1][k]){
                    minCuts[k] = min(minCuts[k], minCuts[p] + 1);
                }
            }
        }
        return minCuts.back();
    }
};
