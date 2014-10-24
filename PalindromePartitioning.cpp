class Solution {
public:
    bool ispalindrome(string &s, int start, int end) {
		for (int i = 0; i <= (end-start)/2; i++)
			if (s[start+i] != s[end-i]) return false;
		return true;
	}
	void f(vector<vector<string>> &vec, string &s, vector<string> &tmp, vector<vector<bool>> &dp, int row) {
		int len = s.size();
		for (int i = row; i < len; i++) {
			if (dp[row][i]) {
				string tmps(s.begin()+row, s.begin()+i+1);
				tmp.push_back(tmps);
				if (i == len-1) vec.push_back(tmp);
				else f(vec, s, tmp, dp, i+1);
				tmp.pop_back();
			}
		}
	}
    vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		if (s.empty()) return ans;
		int len = s.size();
		vector<vector<bool> > dp(len, vector<bool>(len, false));
		unsigned int i, j;
		for (i = 0; i < len; i++) dp[i][i] = true;
		for (i = 0; i < len-1; i++)
			for (j = i+1; j < len; j++) {
				dp[i][j] = ispalindrome(s, i, j);
			}
		vector<string> tmp;
		f(ans, s, tmp, dp, 0);
		return ans;
    }
};
