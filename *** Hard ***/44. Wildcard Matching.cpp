class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size(), prevSuccessIdx = 0;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        s = " " + s; p = " " + p;
        for (int i = 1; i <= n; i ++) {
            if (p[i] == '*') {
                fill(dp[i].begin() + prevSuccessIdx, dp[i].end(), true);
                continue;
            }
            prevSuccessIdx = m + 1;
            for (int j = m; j >= 1; j --) {
                dp[i][j] = p[i] == '?' ? dp[i - 1][j - 1] : p[i] == s[j] && dp[i - 1][j - 1];
                if (dp[i][j]) prevSuccessIdx = j;
            }
        }
        return dp[n][m];
    }
};
