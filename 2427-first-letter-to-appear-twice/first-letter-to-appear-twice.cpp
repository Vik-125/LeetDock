class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> hash;

        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
            if(hash[s[i]] > 1) return s[i];
        }
        return 0;
    }
};