class Solution {
public:
    bool alpha(string g)
    {
        if(g == "") return false;
        for(auto it : g)
        {
            if(isalnum(it) || it == '_') continue;
            else return false;
        }
        return true;
    }
    void useable(string s,string v,vector<string> &r,vector<string> &g,vector<string> &p,vector<string> &e)
    {
        if(s[0] == 'r' || s[0] == 'R') r.push_back(v);
        if(s[0] == 'g' || s[0] == 'G') g.push_back(v);
        if(s[0] == 'e' || s[0] == 'E') e.push_back(v);
        if(s[0] == 'p' || s[0] == 'P') p.push_back(v);
        return;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> r;
        vector<string> g;
        vector<string> p;
        vector<string> e;

        vector<string> result;
        for(int i=0;i<n;i++)
        {
            if(alpha(code[i]))
            {
                if(isActive[i]) useable(businessLine[i],code[i],r,g,p,e);
            }
        }
        sort(e.begin(),e.end());
        sort(p.begin(),p.end());
        sort(g.begin(),g.end());
        sort(r.begin(),r.end());
        result.insert(result.end(),e.begin(),e.end());
        result.insert(result.end(),g.begin(),g.end());
        result.insert(result.end(),p.begin(),p.end());
        result.insert(result.end(),r.begin(),r.end());

        return result;
    }
};