class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> hasht;

        for(auto it : target)
        {
            hasht[it]++;
        }

        unordered_map<char,int> hashs;

        for(auto it : s)
        {
            hashs[it]++;
        }
        int count = INT_MAX;
        int k = INT_MAX;
        for(auto &[key,val] : hasht)
        {
            k = hashs[key] / val;
            count = min(count,k);
        }
        return count;
    }
};