class Solution {
public:
    void sortColors(int A[], int n) {
        int i, j, k;
        i = j = k = 0;
        for (int p = 0; p < n; p++) {
            if (A[p] == 0) {
                A[k++] = 2;
                A[j++] = 1;
                A[i++] = 0;
            } else if (A[p] == 1) {
                A[k++] = 2;
                A[j++] = 1;
            } else A[k++] = 2;
        }
    }
};
