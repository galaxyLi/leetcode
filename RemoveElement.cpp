class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n <= 0) return 0;
        int i, len;
        len = n;
        i = 0;
        while (i < len) {
            if (A[i] == elem) {
                A[i] = A[len-1];
                len -= 1;
            } else {
                i++;
            }
        }
        return len;
    }
};
