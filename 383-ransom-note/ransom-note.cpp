class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hashr;
        unordered_map<char,int> hashm;
        for(auto ch : ransomNote)
        {
            hashr[ch]++;
        }
        for(auto ch : magazine)
        {
            hashm[ch]++;
        }

        for(auto it : hashr)
        {
            if(hashm[it.first] < it.second) return false;
        }

        return true;
    }
};