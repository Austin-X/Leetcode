class Solution {
public:
    vector<string> cb;
    vector<int> atkR, atkC, atkLd, atkRd;
    vector<vector<string>> res;

    void updateBoard(int n, int r, int c, int v) {
        cb[r][c] = v == 1 ? 'Q' : '.';
        atkR[r] += v; atkC[c] += v; atkLd[n - 1 - r + c] += v; atkRd[r + c] += v;
    }

    void dfs(int n, int queens, int startR) {
        if (queens == n) {
            res.push_back(cb);
            return;
        } 
        for (int r = startR; r < n; r ++) {
            for (int c = 0; c < n; c ++) {
                if (!atkR[r] && !atkC[c] && !atkLd[n - 1 - r + c] && !atkRd[r + c]) {
                    updateBoard(n, r, c, 1);
                    dfs(n, queens + 1, r + 1);
                    updateBoard(n, r, c, -1);
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string start(n, '.');
        cb.resize(n, start);
        atkR.resize(n, 0); atkC.resize(n, 0); atkLd.resize(n * 2 - 1, 0); atkRd.resize(n * 2 - 1, 0);
        dfs(n, 0, 0);
        return res;
    }
};
