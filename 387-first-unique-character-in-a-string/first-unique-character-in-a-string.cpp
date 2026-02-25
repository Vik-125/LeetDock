class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hash;

        for(auto it : s) hash[it -'a']++;

        bool flag = false;
        int k = 0;
        for(auto i : s)
        {
            if(hash[i - 'a'] == 1)
            {
                return k;
            }
            k++;
        }
        if(!flag) return -1;
        return 0;
    }
};