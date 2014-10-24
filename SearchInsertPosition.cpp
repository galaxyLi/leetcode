class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	if (n == 0 || target<=A[0]) return 0;
    	if (target > A[n-1]) return n;
        int l, r, m, left, right;
        bool flag = false;
        l = 0;
        r = n-1;
        m = (l+r)/2;
        while (l <= r) {
            if (A[m-1]<target && A[m]>=target) break;
            else if (A[m] < target) l = m+1;
            else r = m-1;
            m = (l+r)/2;
        }
    	return m;
    }
};
