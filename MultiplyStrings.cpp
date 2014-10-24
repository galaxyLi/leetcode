class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
		int len2 = num2.size();
		int len = len1*len2*2;
		char *res = new char[len];
		fill(res, res+len, '0');
		/* i,j,k 三个数组的下表, s 乘积结果, r 进位 */
		int i, j, k, r, s;
		for (i = len1-1; i >= 0; i--) {
			r = s = 0;
			k = len1-1-i;
			for (j = len2-1; j >= 0; j--) {
				s = (res[k]-'0')+(num1[i]-'0')*(num2[j]-'0')+r;
				res[k++] = s%10+'0';
				r = s/10;
			}
			if (r > 0) res[k] = r+'0';
		}

		for (j = len-1; j >= 0; j--)
			if (res[j] != '0') break;
		string ans;
		for (i = j; i >= 0; i--) ans.push_back(res[i]);
		if (ans.empty()) return "0";
		return ans;
    }
};
