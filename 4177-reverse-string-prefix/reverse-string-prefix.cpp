class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();
        string ans = "";
        for(int i=0;i<k;i++) ans += s[i];

        reverse(ans.begin(),ans.end());
        for(int j=k;j<n;j++) ans += s[j];

        return ans;
    }
};