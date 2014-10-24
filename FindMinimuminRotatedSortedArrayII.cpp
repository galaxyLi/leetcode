class Solution {
public:
    int findMin(vector<int> &num) {
        size_t n = num.size();
        if (n == 1) return num[0];
        int l = 0;
        int r = n-1;
        int m;
        while (l < r) {
            if (num[l] < num[r]) break;
            m = l + ((r-l)>>1);
            if (num[m] > num[r]) l = m+1;
            else if (num[m] == num[r]) l++, r--;
            else r = m;
        }
        return num[l];
    }
};
