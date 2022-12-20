class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q; bool vis[n]; memset(vis, false, sizeof(vis));
        q.push(0); vis[0] = true;

        while (!q.empty()) {
            int val = q.front(); q.pop();
            for (int i = 0; i < rooms[val].size(); i ++) if (!vis[rooms[val][i]]) { vis[rooms[val][i]] = true; q.push(rooms[val][i]); }
        }
        return count(vis, vis + n, true) == n;
    }
};
