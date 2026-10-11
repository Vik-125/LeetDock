class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int i = 0;
        int j = 0;
        int n = s.size();
        int length = 0;

        while(j < n){
            char k = s[j];
            hash[k]++;
            if(hash[k] > 1){
                while(i < j && hash[k] > 1){
                    hash[s[i]]--;
                    i++;
                }
            }
            length = max(length, j-i+1);
            j++;
        }
        return length;
    }
};