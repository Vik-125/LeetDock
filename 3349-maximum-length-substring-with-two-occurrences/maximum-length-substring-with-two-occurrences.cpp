class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        int p = 0;
        int n = s.size();
        unordered_map<char,int> hash;
        int len = 0;

        while(p < n){
            char k = s[p];
            hash[k]++;

            if(hash[k] > 2){
                while(hash[k] > 2 && l <= p){
                    hash[s[l]]--;
                    l++;
                }
            }
            else{
                len = max(len, p-l+1);
            }
            p++;
        }
        return len;
    }
};