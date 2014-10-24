class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *tmp = new int[m+n];
        int i, j, k;
        i = j = k = 0;
        while (i < m && j < n) {
            if (A[i] < B[j]) tmp[k++] = A[i++];
            else tmp[k++] = B[j++];
        }
        while (i < m) tmp[k++] = A[i++];
        while (j < n) tmp[k++] = B[j++];
        for (i = 0; i < m+n; i++) A[i] = tmp[i];
        delete tmp;
    }
};
