class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
		int *hgt = new int[n];
		int i, pre, maxh, ans;
		
		maxh = 0; // Record max hgt's max index
		for (i = 1; i < n; i++) maxh = A[i]>=A[maxh] ? i:maxh;
		
		hgt[maxh] = A[maxh];
		hgt[0] = A[0];
		pre = A[0];
		for (i = 1; i < maxh; i++) {
			if (A[i] > pre) {
				pre = A[i];
				hgt[i] = A[i];
			} else hgt[i] = pre;
		}
		hgt[n-1] = A[n-1];
		pre = A[n-1];
		for (i = n-2; i > maxh; i--) {
			if (A[i] > pre) {
				pre = A[i];
				hgt[i] = A[i];
			} else hgt[i] = pre;
		}

		ans = 0;
		for (i = 0; i < n; i++) ans += hgt[i]-A[i];
		return ans;
    }
};
