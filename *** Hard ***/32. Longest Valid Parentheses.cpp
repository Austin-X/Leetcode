class Solution {
public:
    int longestValidParentheses(string s) {
        s = "x" + s;
        int n = s.length(), ans = 0;
        int dp[n + 1];
        fill(dp, dp + n + 1, 0);
        for (int i = 2; i < n; i ++) {
            if (s[i] == '(') continue;
            if (s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
            else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
