class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman;
		roman['I'] = 1;
		roman['V'] = 5;
		roman['X'] = 10;
		roman['L'] = 50;
		roman['C'] = 100;
		roman['D'] = 500;
		roman['M'] = 1000;
        int i, j, len, ans = 0;
		len = s.length();
		i = 0;
		while (i < len) {
			j = i+1;
			if ((j < len) && (roman[s[j]] > roman[s[i]])) {
				ans += roman[s[j]]-roman[s[i]];
				i += 2;
			} else {
				ans += roman[s[i]];
				i++;
			}
		}
		return ans;
    }
};
