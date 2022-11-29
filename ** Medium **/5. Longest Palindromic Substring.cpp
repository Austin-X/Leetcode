class Solution {
public:
    // Dynamic programming solution
    // Time complexity: O(N^2)
    string longestPalindrome(string s) {
        int n = s.length(), maxLength = 1, startingIndexOfAns = 0;
        bool dp[n][n];
        memset(dp, false, sizeof(dp[0][0]) * n * n);
        
        for (int i = 0; i < n; i ++) dp[i][i] = true;
        for (int i = 2; i <= n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (j + i - 1 < n) {
                    if (i % 2 == 0) {
                        if (i == 2) {
                            if (s[j] == s[j + 1]) dp[j][j + 1] = true;
                            else dp[j][j + 1] = false;
                        } else {
                            if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2]) dp[j][j + i - 1] = true;
                            else dp[j][j + i - 1] = false;
                        }
                    } else {
                        if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2]) dp[j][j + i - 1] = true;
                        else dp[j][j + i - 1] = false;
                    }

                    if (dp[j][j + i - 1]) {
                        maxLength = i;
                        startingIndexOfAns = j;
                    }
                }
            }
        }
        
        return s.substr(startingIndexOfAns, maxLength);
    }
};
