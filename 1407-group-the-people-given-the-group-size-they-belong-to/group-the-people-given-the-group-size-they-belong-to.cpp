class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();
        unordered_map<int, vector<int>> hash;

        for (int i = 0; i < n; i++) {
            int k = groupSizes[i];
            hash[k].push_back(i);
            if (hash[k].size() == k) {
                ans.push_back(hash[k]);
                hash[k].clear();
            }
        }
        return ans;
    }
};