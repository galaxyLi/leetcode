class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s && !p) return true;
		if (*p == '\0') return *s == '\0';
		int i, j;
		int lens = strlen(s);
		int lenp = strlen(p);

		const char* tmp = p;
		int cnt = 0;
		while (*tmp != '\0') if (*(tmp++) != '*') cnt++;
		if (cnt > lens) return false;

		bool **dp = new bool*[lens+1];
		for (i = 0; i < lens+1; i++) {
			dp[i] = new bool[lenp+1];
			fill(dp[i], dp[i]+lenp+1, false);
		}
		dp[0][0] = true;
		for (j = 1; j <= lenp; j++) {
			if (dp[0][j-1] && p[j-1]=='*') dp[0][j] = true;
			for (i = 1; i <= lens; i++) {
				if (p[j-1] == '*') dp[i][j] = dp[i][j-1]||dp[i-1][j];
				else if (p[j-1]=='?' || p[j-1]==s[i-1]) {
					dp[i][j] = dp[i-1][j-1];
				} else dp[i][j] = false;
			}
		}
		return dp[lens][lenp];
    }
};
