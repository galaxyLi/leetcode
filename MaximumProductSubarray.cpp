class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) return 0;
        vector<int> pos(n, 0);
        vector<int> neg(n, 0);
        if (A[0] > 0) pos[0] = A[0];
        else neg[0] = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i] > 0) {
                pos[i] = max(A[i], A[i]*pos[i-1]);
                neg[i] = min(0, A[i]*neg[i-1]);
            } else {
                pos[i] = max(0, A[i]*neg[i-1]);
                neg[i] = min(A[i], A[i]*pos[i-1]);
            }
        }
        int max_pro = A[0];
        for (int i = 1; i < n; i++) {
            max_pro = max(max_pro, pos[i]);
        }
        return max_pro;
    }
};
