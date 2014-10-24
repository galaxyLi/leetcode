class Solution {
public:
	map<int, string> phone;
	Solution() {
		phone[0] = " ";
		phone[1] = "";
		phone[2] = "abc";
		phone[3] = "def";
		phone[4] = "ghi";
		phone[5] = "jkl";
		phone[6] = "mno";
		phone[7] = "pqrs";
		phone[8] = "tuv";
		phone[9] = "wxyz";
	}

    vector<string> letterCombinations(string digits) {
		string s("");
		vector<string> ans;
		unsigned int i, len;
		len = digits.length();
		if (len == 0) {
			ans.push_back(s);
			return ans;
		}
		else if (len == 1) {
			for (i = 0; i < phone[digits[0]-'0'].length(); i++) {
				string tmp(phone[digits[0]-'0'].substr(i, 1));
				ans.push_back(tmp);
			}
			return ans;
		} else {
			vector<string> ret = letterCombinations(digits.substr(1));
			for (i = 0; i < phone[digits[0]-'0'].length(); i++) {
				string prefix(phone[digits[0]-'0'].substr(i, 1));
				for (vector<string>::iterator iter = ret.begin(); iter != ret.end(); iter++) {
					string tmp = prefix + *iter;
					ans.push_back(tmp);
				}
			}
			return ans;
		}
    }
};
