bool isMatch(char *s, char *p) {
    if (p[0] == '\0') return s[0] == '\0';
    else if (p[0] != '.') {
        if (s[0] != p[0]) return p[1] == '*' ? isMatch(s, p + 2) : false;
        else if (p[1] == '*') {
            int idx = 0;
            while (s[idx++] == p[0]) if (isMatch(s + idx, p + 2)) return true;
            return isMatch(s, p + 2);
        } else return isMatch(s + 1, p + 1);
    } else {
        if (s[0] == '\0') return p[1] == '*' ? isMatch(s, p + 2) : false;
        if (p[1] == '*') {
            if (p[2] == '.' && p[3] == '*') return isMatch(s, p + 2); 
            int idx = 0;
            while (s[idx++] != '\0') if (isMatch(s + idx, p + 2)) return true;
            return isMatch(s, p + 2);
        } else return isMatch(s + 1, p + 1);
    }
}
