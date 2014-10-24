class Solution {
public:
	bool isvalid(char c) {
		if (isdigit(c)) return true;
		if (isalpha(c)) return true;
		return false;
	}
    bool isPalindrome(string s) {
		int len = s.size();
		int l = 0, r = len-1;
		while (l <= r) {
			while (l<r && !isvalid(s[l])) l++;
			while (r>l && !isvalid(s[r])) r--;
			if (tolower(s[l]) == tolower(s[r])) {
				l++;
				r--;
			} else return false;
		}
		return true;
    }
};
