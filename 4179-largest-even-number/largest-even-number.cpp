class Solution {
public:
    string largestEven(string s) {
        int n = s.size()-1;

        for(int i=n;i>=0;i--){
            if(s[i] % 2 == 0) return s.substr(0, i+1);
        }
        return "";
    }
};