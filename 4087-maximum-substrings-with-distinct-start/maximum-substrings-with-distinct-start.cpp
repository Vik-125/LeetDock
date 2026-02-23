class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int> hash;

        for(auto it : s) hash[it]++;

        return hash.size();
    }
};