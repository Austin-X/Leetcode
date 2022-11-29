class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.length(), idx = 0;
        string res(n, 'x');

        for (int i = 0; i < n; i += 2 * (numRows - 1)) res[idx++] = s[i];
        for (int i = 1; i < numRows - 1; i ++) {
            for (int j = i; j < n;) {
                res[idx++] = s[j];
                j += 2 * (numRows - i - 1);
                if (j >= n) continue;
                res[idx++] = s[j];
                j += 2 * i;
            }
        }
        for (int i = numRows - 1; i < n; i += 2 * (numRows - 1)) res[idx++] = s[i];
        
        return res;
    }
};
