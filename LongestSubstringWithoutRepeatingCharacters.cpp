class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, k, len, max = 0;
		bool flag;
		len = s.size();
		if (len) max = 1;
		i = 0;
		j = 1;
		while (i < len-1) {
			while (j < len) {
				flag = true;
				for (k = i; k < j; k++) {
					if (s[k] == s[j]) {
						flag = false;
						break;
					}
				}
				if (flag) j++;
				else {
					max = (j-i)>max ? (j-i):max;
					i = k+1;
				}
			}
			if (j == len) {
				if (flag) max = (j-i)>max ? (j-i):max;
				break;
			}
		}
		return max;
    }
};
