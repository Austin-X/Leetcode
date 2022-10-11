int lengthOfLongestSubstring(char * s) {
    int n = strlen(s);
    int ptr1 = 0, ptr2 = 0, ans = 0, curlen = 0;
    int vis[255] = {0};
    while (ptr2 < n) {
        if (!vis[s[ptr2]]) {
            curlen ++;
            if (curlen > ans) ans = curlen;
            vis[s[ptr2]] = 1;
        } else {
            while (s[ptr1] != s[ptr2]) {
                vis[s[ptr1]] = 0;
                ptr1 ++;
                curlen --;
            }
            ptr1 ++;
        }
        ptr2 ++;
    }
    return ans;
}
