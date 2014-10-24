class Solution {
public:
    int minDistance(string word1, string word2) {
        int i, j, k, len1, len2;
        len1 = word1.length();
        len2 = word2.length();
        int dp[len1+1][len2+1];
        dp[0][0] = 0;
        for (i = 1; i <= len1; i++) dp[i][0] = i;
        for (j = 1; j <= len2; j++) dp[0][j] = j;
        for (i = 1; i <= len1; i++)
            for (j = 1; j <= len2; j++) {
                int dis = (word1[i-1]==word2[j-1] ? 0:1);
                dp[i][j] = min(dp[i-1][j-1]+dis, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        return dp[len1][len2];
    }
};
