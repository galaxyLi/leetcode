class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        stack<int> stk;
        vector<int> ans;
        int len = digits.size();
        int i, s, r = 1;
        for (i = len-1; i >= 0; i--) {
            s = digits[i]+r;
            stk.push(s%10);
            r = s/10;
        }
        if (r != 0) stk.push(r);
        while (!stk.empty()) {
            int tp = stk.top();
            stk.pop();
            ans.push_back(tp);
        }
        return ans;
    }
};
