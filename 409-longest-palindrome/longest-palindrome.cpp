class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();

        unordered_map<char,int> hash;
        for(auto it : s)
        {
            hash[it]++;
        }

        int ans = 0;
        for(auto i : hash)
        {
            if(i.second % 2 == 0) ans += i.second;
            else if(i.second % 2 != 0 && i.second > 1) ans += (i.second-1);
        }
        cout << ans;
        return ans == n ? ans : ans + 1;
    }
};