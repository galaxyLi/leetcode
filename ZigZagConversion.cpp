class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows < 1) return NULL;
		if (s.empty() || nRows == 1) return s;

		int len, step, step2, i, j, k;
		len = s.length();
		string ans(len, '0');
		j = k = 0;
		step = 2*(nRows-1);

		while (j < len) {
			ans[k++] = s[j];
			j += step;
		}
		for (i = 1; i < nRows-1; i++) {
			step2 = step - 2*i;
			j = i;
			while (j < len) {
				ans[k++] = s[j];
				if (j+step2 < len) ans[k++] = s[j+step2];
				j += step;
			}
		}
		j = nRows-1;
		while (j < len) {
			ans[k++] = s[j];
			j += step;
		}
		return ans;
    }
};
