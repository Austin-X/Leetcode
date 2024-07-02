class Solution {
public:
    struct crd { int r, c; vector<int> candidates; };
    int b[10][10], ans[10][10];

    void check() {
        for (int i = 0; i < 9; i ++) {
            vector<bool> visR(10, false), visC(10, false), visSq(10, false);
            for (int j = 0; j < 9; j ++) {
                int vr = b[i][j], vc = b[j][i], vsq = b[i / 3 * 3 + j / 3][i / 3 * 3 + j % 3];
                if (vr == -1 || vc == -1 || vsq == -1) return;
                visR[vr] = true; visC[vc] = true; visSq[vsq] = true;
            }
            for (int j = 1; j <= 9; j ++) if (!visR[j] || !visC[j] || !visSq[j]) return;
        }
        copy(&b[0][0], &b[0][0] + 10 * 10, &ans[0][0]);
    }

    crd getCandidate() { 
        crd best = {-1, -1, vector<int>(10, 0)};
        for (int i = 0;  i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (b[i][j] != -1) continue;
                vector<bool> vis(10, false);
                for (int k = 0; k < 9; k ++) {
                    int vr = b[i][k], vc = b[k][j], vsq = b[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3];
                    if (vr != -1) vis[vr] = true;
                    if (vc != -1) vis[vc] = true;
                    if (vsq != -1) vis[vsq] = true;
                }
                vector<int> temp;
                for (int k = 1; k <= 9; k ++) if (!vis[k]) temp.push_back(k);
                if (temp.size() < best.candidates.size()) best = {i, j, temp};
            }
        }
        return best;
    }

    void rec() {
        crd cd = getCandidate();
        if (cd.r == -1) return;
        for (int x: cd.candidates) {
            b[cd.r][cd.c] = x;
            check();
            rec();
            b[cd.r][cd.c] = -1;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i ++) for (int j = 0; j < 9; j ++) b[i][j] = board[i][j] == '.' ? -1 : board[i][j] - '0';
        rec();
        for (int i = 0; i < 9; i ++) for (int j = 0; j < 9; j ++) board[i][j] = (char)(ans[i][j] + '0');
    }
};
