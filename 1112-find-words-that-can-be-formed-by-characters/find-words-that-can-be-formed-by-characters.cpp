class Solution {
public:
    bool check(string s,unordered_map<char,int> hash)
    {
        for(auto it : s)
        {
            if(hash[it] <= 0) return false;
            hash[it]--;
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> hash;
        int count = 0;

        for(char st : chars)
        {
            hash[st]++;
        }
        for(auto it : words)
        {
           if (check(it,hash))
           {
            count += it.size();
           }
        }
        return count;
    }
};