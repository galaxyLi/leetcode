class Solution {
public:
    void f(string &s, int sum, int start, int end, int k) {
		if (k == 1) return;
		int i, j;
		j = ((k-1)*(end-start))/sum;
		char tmp = s[start+j];
		for (i = start+j; i > start; i--) s[i] = s[i-1];
		s[start] = tmp;
		f(s, sum/(end-start), start+1, end, k-j*sum/(end-start));
	}
    string getPermutation(int n, int k) {
        int i, sum = 1;
        char *str = new char[n+1];
        for (i = 1; i <= n; i++) {
        	sum *= i;
        	str[i-1] = i+'0';
        }
        string s(str);
        if (k > sum) return "";
        f(s, sum, 0, n, k);
        return s;
    }
};
