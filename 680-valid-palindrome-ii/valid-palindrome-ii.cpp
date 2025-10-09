class Solution {
public:
    bool check(string s,int left,int right)
    {
        while(left <= right)
        {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while(l <= r)
        {
            if(s[l] != s[r])
            {
                return (check(s,l + 1,r) || check(s,l,r - 1));
            }
            l++;
            r--;
        }
        return true;
    }
};