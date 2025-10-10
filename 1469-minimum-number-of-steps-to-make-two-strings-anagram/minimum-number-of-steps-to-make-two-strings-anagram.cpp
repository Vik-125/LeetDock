class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> hash;
        for(auto it : s)
        {
            hash[it]++;
        }

        int count = 0;
        for(auto it : t)
        {
            if(hash[it] > 0) hash[it]--;
            else count++;
        }

        return count;
    }
};