bool isMatch(char *s, char *p) {
    int n = strlen(s), m = strlen(p), k;
    bool dp[n + 1][m + 1];
    for (int i = 0; i <= n; i ++) for (int j = 0; j <= m; j ++) dp[i][j] = false;
    dp[n][m] = true;
    for (int i = m - 1; i >= 0 && p[i] == '*'; i -= 2) dp[n][i - 1] = true;

    for (int i = n - 1; i >= 0; i --) {
        for (int j = m - 1; j >= 0; j --) {
            if (p[j] == '*') dp[i][j] = false;
            else if (p[j] == '.') {
                if (j < m - 1 && p[j + 1] == '*') {
                    for (k = i; k < n; k ++) dp[i][j] = fmax(dp[i][j], dp[k][j + 2]);
                    dp[i][j] = fmax(dp[i][j], dp[k][j + 2]);
                }
                else dp[i][j] = dp[i + 1][j + 1];
            } else {
                if (j < m - 1 && p[j + 1] == '*') {
                    if (p[j] == s[i]) {
                        for (k = i; s[k] == p[j]; k ++) dp[i][j] = fmax(dp[i][j], dp[k][j + 2]);
                        dp[i][j] = fmax(dp[i][j], dp[k][j + 2]);
                    }
                    else dp[i][j] = dp[i][j + 2];
                } else if (s[i] == p[j]) dp[i][j] = dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}
