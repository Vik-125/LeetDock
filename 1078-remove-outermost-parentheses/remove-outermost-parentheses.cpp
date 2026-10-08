class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int starting = 0;
        int closing = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                if(starting == 0)
                {
                    starting++;
                }
                else if(starting >= 1)
                {
                    ans.push_back(s[i]);
                    starting++;
                }
            }
            else if(s[i] == ')')
            {
                if(starting > 1)
                {
                    ans.push_back(s[i]);
                    starting--;
                }
                else if(starting == 1) starting--;
            }
        }
        return ans;
    }
};