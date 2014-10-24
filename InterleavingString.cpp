class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if (s1.size() + s2.size() != s3.size())
                return false;
            if (s1.size() < s2.size())
                s1.swap(s2);
            vector<bool>  dp(s1.size() + 1);
            dp[0] = true;
            for (size_t j = 0; j <= s2.size(); ++j)
                for (size_t i = 1; i <= s1.size(); ++i)
                    dp[i] = ((dp[i - 1] && s1[i - 1] == s3[i + j - 1]) ||
                    (j > 0 && dp[i] && s2[j - 1] == s3[i + j - 1]));
            return dp[s1.size()];
        }
};
