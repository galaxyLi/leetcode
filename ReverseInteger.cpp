class Solution {
public:
    int reverse(int x) {
        int i, ret, flag = false;
        if (x == 0) {
            return 0;
        }
        if (x < 0) {
            flag = true;
            x = -x;
        }
        ret = 0;
        while (x > 0) {
            i = x % 10;
            ret = ret*10 + i;
            x /= 10;
        }
        if (flag) ret = -ret;
        return ret;
    }
};
