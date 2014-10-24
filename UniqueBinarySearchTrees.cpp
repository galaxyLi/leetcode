class Solution {
public:
    unsigned long int f(int x) {
        if (x == 1) return 1;
		if (x == 2) return 2;
		if (x == 3) return 5;
		return f(x-1)*(4*x-2)/(x+1);
    }
    int numTrees(int n) {
		return f(n);
    }
};
