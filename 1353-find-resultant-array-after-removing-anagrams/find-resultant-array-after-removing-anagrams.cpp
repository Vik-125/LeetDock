class Solution {
public:
    bool check(const string& s, const unordered_map<char, int>& has) {
        unordered_map<char, int> hash;
        for (char c : s) {
            hash[c]++;
        }
        return hash == has;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        if (n > 0) {
            ans.push_back(words[0]);
        }

        for (int i = 1; i < n; ++i) {
            unordered_map<char, int> hash;
            for (char c : words[i]) {
                hash[c]++;
            }

            if (!check(ans.back(), hash)) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};