class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> digits(n);
        iota(digits.begin(), digits.end(), '1');
        int fact[n]; fact[0] = 1;
        for (int i = 1; i < n; i ++) fact[i] = fact[i - 1] * i;

        string ans = "";
        for (int i = 0; i < n; i ++) {
            int div = fact[n - 1 - i], quot = k / div, rem = k % div;
            if (rem == 0 && quot > 0) quot --;
            ans += digits[quot];
            digits.erase(digits.begin() + quot);
            k -= quot * div;
        }

        return ans;
    }
};
