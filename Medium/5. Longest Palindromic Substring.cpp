class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.length(); i ++) {
            // Odd length palindromes
            string cur = s.substr(i, 1);
            int j = i - 1, k = i + 1;
            while (j >= 0 && k < s.length()) {
                if (s[j] == s[k]) {
                    cur = s.substr(j, k - j + 1);
                    j --;
                    k ++;
                } else break;
            }
            if (cur.length() > ans.length()) ans = cur;

            // Even length palindromes
            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                string cur =  s.substr(i, 2);
                j = i - 1; k = i + 2;
                while (j >= 0 && k < s.length()) {
                    if (s[j] == s[k]) {
                        cur = s.substr(j, k - j + 1);
                        j --;
                        k ++;
                    } else break;
                }
                if (cur.length() > ans.length()) ans = cur;
            }
        }

        return ans;
    }
};
