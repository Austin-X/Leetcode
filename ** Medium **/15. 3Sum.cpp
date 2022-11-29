class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i ++) m[nums[i]] ++;
        
        for (int i = 0; i < n; i ++) {
            m[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j ++) {
                int sum = nums[i] + nums[j];
                if (-sum < nums[j]) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                m[nums[j]]--;
                if (m[-sum] > 0) {
                    vector<int> temp = {-sum, nums[i], nums[j]};
                    ans.push_back(temp);
                }
                m[nums[j]]++;
            }
        }

        return ans;
    }
};
