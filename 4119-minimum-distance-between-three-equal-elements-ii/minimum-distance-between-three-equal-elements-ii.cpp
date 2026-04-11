class Solution {
public:
    int find(vector<int>& ind) {
        int n = ind.size();
        int dis = INT_MAX;
        for (int i = 0; i <= n - 3; i++) {
            dis = min(dis,
                      (abs(ind[i] - ind[i + 1]) + abs(ind[i + 1] - ind[i + 2]) +
                       abs(ind[i] - ind[i + 2])));
        }
        return dis;
    }
    int minimumDistance(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        unordered_map<int, vector<int>> hash;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]].push_back(i);
            if (hash[nums[i]].size() >= 3) {
                if (hash[nums[i]].size() > 3) {
                    hash[nums[i]].erase(hash[nums[i]].begin());
                }
                ans = min(find(hash[nums[i]]), ans);
                if(ans == 0) break;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};