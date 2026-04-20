class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();
        unordered_map<int, vector<int>> hash;;
\
        for (int i = 0; i < n; i++) {
            hash[groupSizes[i]].push_back(i);
            if (hash[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(hash[groupSizes[i]]);
                hash[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};