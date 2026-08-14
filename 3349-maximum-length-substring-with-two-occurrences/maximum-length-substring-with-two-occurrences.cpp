class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        int p = 0;
        int n = s.size();
        vector<int> arr(26,0);
        int len = 0;

        while(p < n){
            arr[s[p] - 'a'] += 1;

            if(arr[s[p] - 'a'] > 2){
                while(arr[s[p] - 'a'] > 2 && l <= p){
                    arr[s[l] - 'a']--;
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