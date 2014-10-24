class Solution {
public:
    int sqrt(int x) {
        if (x <= 0) return 0;
        double x1 = 1, x2;
        while (true) {
            x2 = 0.5*(x1+x/x1);
            if (abs(int(x1-x2)) < 1) return x2;
            x1 = x2;
        }
    }
};
