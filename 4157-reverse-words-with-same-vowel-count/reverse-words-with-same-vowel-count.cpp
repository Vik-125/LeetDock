class Solution {
public:
    bool check(string s,int vow)
    {
        int n = s.size();
        int l = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u') l++;
        }
        return l == vow;
    }
    string reverseWords(string s) {
        stringstream ss(s);
        string word,result;
        vector<string> words;

        while(ss >> word)
        {
            words.push_back(word);
        }

        int vow = 0;
        string first = words[0];
        for(int i=0;i<first.size();i++)
        {
            if(first[i] == 'a' || first[i] == 'o' || first[i] == 'e' || first[i] == 'i' || first[i] == 'u') vow++;
        }
        for(int i=1;i<words.size();i++)
        {
            if(check(words[i],vow))
            {
                reverse(words[i].begin(),words[i].end());
            }
        }

        for(int i=0;i<words.size();i++)
        {
            result += words[i];
            if(i < words.size()-1) result += " ";
        }
        return result;
    }
};