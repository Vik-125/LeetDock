class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        //sort(strs.begin(),strs.end());

        int n = strs.size();
        int f = strs[0].size();
        
        for(int i=0;i<f;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(strs[j][i] == strs[j+1][i]) continue;
                else return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};