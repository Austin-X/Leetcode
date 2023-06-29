class Solution {
public:
    typedef pair<int, char> pic;

    int longestValidParentheses(string s) {
        stack<pic> stk;
        
        int n = s.length();
        if (n == 0) return 0;

        bool valid[n];
        fill(valid, valid + n, false);

        for (int i = 0; i < n; i ++) {
            if (!stk.empty() && s[i] == ')' && stk.top().second == '(') {
                for (int j = stk.top().first; j <= i; j ++) valid[j] = true;
                stk.pop();
            } else stk.push({i, s[i]});
        }

        int temp = 0, ans = 0;
        for (int i = 0; i < n; i ++) {
            if (valid[i]) temp ++;
            else {
                ans = max(ans, temp);
                temp = 0;
            }
        }
        ans = max(ans, temp);
        
        return ans;
    }
};
