class Solution {
public:
    void f(int n, int left, string tmp, vector<string> &ans) {
        if (n == 0) {
            for (int i = 0; i < left; i++) tmp += ")";
            ans.push_back(tmp);
            return;
        } else {
            if (left == 0) {
                f(n-1, 1, tmp+"(", ans);
            } else {
                f(n-1, left+1, tmp+"(", ans);
                f(n, left-1, tmp+")", ans);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) return ans;
        string tmp("(");
        f(n-1, 1, tmp, ans);
        return ans;
    }
};
