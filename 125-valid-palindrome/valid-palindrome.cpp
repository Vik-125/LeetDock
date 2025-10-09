class Solution {
public:
    bool isPalindrome(string s) {
        string ans;

        for(auto it : s)
        {
            if(isalnum(it))
            {
                ans += tolower(it);
            }
        }
        
        int l = 0;
        int r = ans.size() - 1;

        while(l <= r)
        {
            if(ans[l] != ans[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};