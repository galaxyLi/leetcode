class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0, last = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            if (i > last) {
                if (last==curr && last<n-1) return -1;
                last = curr;
                ret++;
            }
            curr = max(curr, i+A[i]);
        }
        return ret;
    }
};
