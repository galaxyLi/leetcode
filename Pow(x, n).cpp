class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
		if (x == 0) return 0;
		if (n < 0) {
			if (n == 0x80000000) return (1/x)*pow(1/x, 0x7fffffff);
			else return pow(1/x, -n);
		}
		if (n%2 == 0) {
			return pow(x*x, n/2);
		} else {
			return x*pow(x*x, n/2);
		}
    }
};
