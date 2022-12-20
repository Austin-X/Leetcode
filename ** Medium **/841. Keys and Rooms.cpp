class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q; bool vis[n]; memset(vis, false, sizeof(vis));
        q.push(0); vis[0] = true;

        while (!q.empty()) {
            int val = q.front(); q.pop();
            for (int x: rooms[val]) if (!vis[x]) { vis[x] = true; q.push(x); }
        }
        return count(vis, vis + n, true) == n;
    }
};
