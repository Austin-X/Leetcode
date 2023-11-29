class Solution {
public:
    static const int MN = 100;
    int color[MN + 1];

    bool bfs(vector<vector<int>>& graph, int start) {
        bool flag = true;
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: graph[u]) {
                if (color[v] == color[u]) flag = false;
                else if (color[v] == -1) {
                    color[v] = !color[u];
                    q.push(v);
                }
            }
        }
        return flag;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        fill(color, color + MN, -1);
        for (int i = 0; i < n; i ++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!bfs(graph, i)) return false;
            }
        }
        return true;
    }
};
