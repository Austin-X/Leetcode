class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.length(), m = words[0].length(), tot = words.size() * m;
        string match[n];
        fill(match, match + n, "-1");

        for (int i = 0; i <= n - m; i ++) {
            string temp = s.substr(i, m);
            if (find(words.begin(), words.end(), temp) != words.end()) match[i] = temp;
        }

        for (int i = 0; i <= n - tot; i ++) {
            unordered_map<string, int> mp;
            for (string x: words) mp[x] ++;
            for (int j = i; j < i + tot; j += m) {
                if (!mp.count(match[j])) break;
                mp[match[j]] --;
                if (mp[match[j]] == 0) mp.erase(match[j]);
            }
            if (mp.empty()) res.push_back(i);
        }
        return res;
    }
};
