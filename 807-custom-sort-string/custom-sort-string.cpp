class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> hash;
        for(auto it : s) hash[it]++;

        string ans = "";
        for(auto it : order)
        {
            while(hash[it] != 0){
                ans += it;
                hash[it]--;
            }
        }
        for(auto it : hash)
        {
            while(it.second != 0){
                ans += it.first;
                it.second--;
            }
        }

        return ans;
    }
};