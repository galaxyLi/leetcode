class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int f1 = 1, f2 = 2, tmp, i;
        for (i = 3; i <= n; i++) {
            tmp = f1;
            f1 = f2;
            f2 = tmp+f2;
        }
        return f2;
    }
};
