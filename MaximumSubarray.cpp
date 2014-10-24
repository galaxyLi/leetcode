class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans = 0x80000000, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum <= 0) {
                sum = A[i];
                ans = max(sum, ans);
            } else {
                sum += A[i];
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};
