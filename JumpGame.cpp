class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) return true;
        bool *can = new bool[n];
        fill(can, can+n, false);
        can[n-1] = true;
        int pos = n-1; // record the recent position can reach the last index
        for (int i = n-2; i >= 0; i--) {
            if (i+A[i] >= pos) {
                can[i] = true;
                pos = i;
            }
        }
        return can[0];
    }
};
