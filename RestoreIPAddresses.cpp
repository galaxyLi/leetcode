class Solution {
public:
    bool isvalid(string s) {
		int len = s.size();
		if (len==0 || len>3) return false;
		if (stoi(s) > 255) return false;
		if (len>1 && s[0]=='0') return false;
		return true;
	}
	void f(vector<string> &ans, string s, int len, int step, string des) {
		if (step == 4) {
			if (isvalid(s)) {
				des += ".";
				des += s;
				ans.push_back(des);
				return;
			}
		} else {
			string tmp, tmpd;
			for (int i = 1; i<=3&&i<=len; i++) {
				tmp = s.substr(0, i);
				tmpd = des;
				if (isvalid(tmp)) {
					if (step != 1) tmpd += ".";
					tmpd += tmp;
					f(ans, s.substr(i, len-i), len-i, step+1, tmpd);
				}
			}
		}
	}
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
		int len = s.size();
		if (len < 4) return ans;
		f(ans, s, len, 1, "");
		return ans;
    }
};
