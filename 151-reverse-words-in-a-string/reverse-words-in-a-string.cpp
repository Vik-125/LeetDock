class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word,result;
        vector<string> words;

        while(ss >> word)
        {
            words.push_back(word);
        }
        reverse(words.begin(),words.end());

        int n = words.size()-1;
        int i = 0;
        for(auto it : words)
        {
            result += it;
            if(i < n) result += " ";
            i++;
        }
        return result;
    }
};