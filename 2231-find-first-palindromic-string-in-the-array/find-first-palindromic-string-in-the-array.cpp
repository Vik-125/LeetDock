class Solution {
public:
    bool check(string st)
    {
        int l = 0;
        int r = st.size() - 1;

        while(l <= r)
        {
            if(st[l] != st[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it : words)
        {
            if(check(it)) return it;
        }
        return "";
    }
};