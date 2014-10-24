class Solution {
public:
    void dfs(string &s, int k, vector<vector<bool>> &dp, vector<string> &vec, vector<string> &ans, unordered_set<string> &dict) {
		int len = s.size();
		if (k >= len) {
			if (!vec.empty()) {
				string ret;
				for (int i = 0; i < vec.size(); i++) {
					ret.append(vec[i]);
					if (i != vec.size()-1) ret.append(" ");
				}
				ans.push_back(ret);
				return;
			}
		}
		for (int l = 1; l+k <= len; l++) {
			string tmp = s.substr(k, l);
			if (dict.count(tmp)>0 && dp[len-l-k][k+l]) {
				vec.push_back(tmp);
				dfs(s, k+l, dp, vec, ans, dict);
				vec.pop_back();
			}
		}
	}
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int i, l, len = s.size();
		vector<vector<bool> > dp(len+1, vector<bool>(len+1, false));
		for (i = 0; i <= len; i++) dp[0][i] = true;
		for (l = 1; l <= len; l++) {
			for (i = 0; i+l <= len; i++) {
				string tmp = s.substr(i, l);
				if (dict.count(tmp) > 0) dp[l][i] = true;
				else {
					for (int left = 1; left < len; left++) {
						dp[l][i] = dp[left][i] && dp[l-left][i+left];
						if (dp[l][i]) break;
					}
				}
			}
		}
		vector<string> ans;
		if (!dp[0][len]) return ans;
		vector<string> vec;
		dfs(s, 0, dp, vec, ans, dict);
		return ans;
    }
};
