class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 0) return 0;
        int i, j, len, pre, cnt;
        pre = A[0];
        cnt = 1;
        len = n;
        i = 1;
        while (i < len) {
            if (A[i]==pre) {
                if (cnt == 2) {
                    for (j = i; j < len-1; j++) A[j] = A[j+1];
                    len -= 1;
                } else {
                    cnt++;
                    i++;
                }
            } else {
                pre = A[i];
                cnt = 1;
                i++;
            }
        }
        return len;
    }
};
