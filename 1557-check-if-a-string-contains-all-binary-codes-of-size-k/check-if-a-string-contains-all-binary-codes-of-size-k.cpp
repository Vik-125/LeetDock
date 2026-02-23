class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> hash;
        for(int i=0;i+k<=s.size();i++)
        {
            hash.insert(s.substr(i, k));
        }
        int codes = pow(2,k);
        return codes == hash.size();
    }
};