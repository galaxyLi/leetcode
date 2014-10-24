class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        if (n == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int l, r, m, left, right;
        bool flag = false;
        l = 0;
        r = n-1;
        m = (l+r)/2;
        while (l <= r) {
            if (A[m] == target) {
                flag = true;
                if (m > 0 && A[m-1] == target) r = m-1;
                else break;
            } else if (A[m] < target) l = m+1;
            else r = m-1;
            m = (l+r)/2;
        }
        if (flag) {
            left = m;
            ans.push_back(left);
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        l = 0;
        r = n-1;
        m = (l+r)/2;
        while (l <= r) {
            if (A[m] == target) {
                if (m < n-1 && A[m+1] == target) l = m+1;
                else break;
            } else if (A[m] < target) l = m+1;
            else r = m-1;
            m = (l+r)/2;
        }
        right = m;
        ans.push_back(right);
        return ans;
    }
};
