class Solution {
public:
    int divide(int dividend, int divisor) {
#define INTMAX 0x7fffffff
#define INTMIN 0x80000000
		bool fa = true, fb = true;
		unsigned int a, b;

		if (dividend < 0) a = -dividend, fa = false;
		else a = dividend;
		if (divisor < 0) b = -divisor, fb = false;
		else b = divisor;

		if (b == 0) {
			if (fa) return INTMAX;
			else return INTMIN;
		} else if (b == 1) {
			if (fa ^ fb) return -(signed)a;
			else return a;
		} else if (a < b) return 0;

		unsigned int ans = 0, i = 0, j = b, k = a;
		while (true) {
			while (k > j) {
				if (i == 0) i = 1;
				else i += i;
				j += j;
			}
			if (k == j) {
				if (i == 0) i = 1;
				else i += i;
				ans += i;
				break;
			} else {
				ans += i;
				i = 0;
				j = j>>1;
				k -= j;
				j = b;
				if (k < j) break;
			}
		}
		if (fa ^ fb) return -(signed)ans;
		else return ans;
    }
};
