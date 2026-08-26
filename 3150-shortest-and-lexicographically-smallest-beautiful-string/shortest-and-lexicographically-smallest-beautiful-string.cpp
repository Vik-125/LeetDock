class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int smallLength = n;
        int i=0, j=0;
        int cnt = 0;
        string sub = "";
        string result = "";

        while(j < n){
            if(s[j] == '1') cnt++;
        
            if(cnt > k){
                while(cnt > k){
                    if(s[i] == '1') cnt--;
                    i++;
                }
            }

            if(cnt == k){
                while(s[i] == '0'){
                    i++;
                }
                if(smallLength > j-i+1 || smallLength == j-i+1 && (s.substr(i, j - i + 1) < result || result == "") ){
                    smallLength = j-i+1;
                    result = s.substr(i, j - i + 1);
                }
            }
            j++;
        }
        return result;
    }
};