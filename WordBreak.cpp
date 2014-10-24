class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		int i, j, len = s.size();
		vector<vector<bool> > dp(len, vector<bool>(len, false));
		for (i = 0; i < len; i++) {
			for (j = 0; j < len-i; j++) {
				string tmp = s.substr(i, j+1);
				if (dict.find(tmp) != dict.end()) {
					dp[i][j] = true;
					if (i > 0 && dp[0][i-1]) dp[0][i+j] = true;
				}
			}
		}
		return dp[0][len-1];
    }
};
