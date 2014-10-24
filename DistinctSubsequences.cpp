class Solution {
public:
    int numDistinct(string S, string T) { 
		unsigned int ls, lt, i, j;
		ls = S.length();
		lt = T.length();
		if (ls < lt) return 0;
		int **dp = new int*[lt+1];
		for (i = 0; i < lt+1; i++) dp[i] = new int[ls+1];
		dp[0][0] = 1;
		for (i = 1; i < lt+1; i++) dp[i][0] = 0;
		for (j = 1; j < ls+1; j++) dp[0][j] = 1;

		for (i = 1; i <= lt; i++) {
			for (j = 1; j <= ls; j++) {
				dp[i][j] = dp[i][j-1];
				if (S[j-1] == T[i-1]) dp[i][j] += dp[i-1][j-1];
			}
		}
		return dp[lt][ls];
    }
};
