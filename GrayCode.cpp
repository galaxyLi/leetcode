class Solution {
public:
    void f(int n, vector<int> &vec) {
        if (n == 0) {vec.push_back(0); return;}
        if (n == 1) {
            vec.push_back(0);
            vec.push_back(1);
            return;
        }
        f(n-1, vec);
        int i, len = vec.size(), mask = 1<<(n-1);
        for (i = len-1; i >= 0; i--) vec.push_back(mask|vec[i]);
    }
    vector<int> grayCode(int n) {
        vector<int> ans;
        f(n, ans);
        return ans;
    }
};
