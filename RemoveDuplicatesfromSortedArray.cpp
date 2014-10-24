class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 0) return 0;
        int i, j, len, pre;
        pre = A[0];
        len = n;
        i = 1;
        while (i < len) {
            if (A[i] == pre) {
                for (j = i; j < len-1; j++) A[j] = A[j+1];
                len -= 1;
            } else {
                pre = A[i];
                i++;
            }
        }
        return len;
    }
};
