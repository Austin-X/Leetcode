class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < height.size(); i ++) {
            int h = height[i], h_idx = i;
            while (!st.empty() && h > st.top().second) {
                pair<int, int> p = st.top(); st.pop();
                if (!st.empty()) {
                    ans += (i - p.first) * (min(st.top().second, h) - p.second);
                    h_idx = p.first;
                }
            }
            if (st.empty() || h < st.top().second) st.push({h_idx, h});
        }
        return ans;
    }
};
