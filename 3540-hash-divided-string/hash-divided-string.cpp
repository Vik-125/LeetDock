class Solution {
public:
    char find(string trp){
        int sum = 0;
        for(auto it : trp){
            sum += it - 'a';
            cout << sum << " ";
        }
        sum %= 26;
        cout << (sum) << " ";
        return ('a' + sum);
    }
    string stringHash(string s, int k) {
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i =  i+k){
            string temp = "";
            for(int j=i;j<i+k;j++){
                temp += s[j];
            }
            ans += find(temp);
        }
        return ans;
    }
};