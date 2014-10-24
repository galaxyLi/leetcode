class Solution {
    public:
        string ItoStr(int n) {
            stringstream ss;
            ss << n;
            return ss.str();
        }
        string f(string num) {
            string ans;
            int i, j, pre, len = num.length();
            pre = num[0];
            j = 1;
            for (i = 1; i < len; i++) {
                if (num[i] == pre) j++;
                else {
                    ans.append(ItoStr(j));
                    ans.append(ItoStr(pre-'0'));
                    pre = num[i];
                    j = 1;
                }
            }
            ans.append(ItoStr(j));
            ans.append(ItoStr(pre-'0'));
            return ans;
        }
        string countAndSay(int n) {
            string ans;
            if (n < 1) return ans;
            ans = "1";
            while (--n) ans = f(ans);
            return ans;
        }
};
