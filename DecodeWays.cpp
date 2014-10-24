class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
		if (len==0 || s[0]=='0') return 0;
		if (len == 1) return 1;
		int f1, f2, f;
		f1 = f2 = 1;
		for (int i = 1; i < len; i++) {
			if (s[i] == '0') {
				if (s[i-1]=='1' || s[i-1]=='2') f = f1;
				else return 0;
			} else {
				if (s[i-1]=='1' || (s[i-1]=='2'&&s[i]<'7')) f = f1+f2;
				else f = f2;
			}
			f1 = f2;
			f2 = f;
		}
		return f2;
    }
};
