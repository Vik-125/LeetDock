class Solution {
public:
    string sortVowels(string s) {
        vector<int> upper;
        vector<int> lower;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                if ((s[i] - '0') >= 65 || (s[i] - '0') <= 90) {
                    upper.push_back(s[i] - '0');
                    s[i] = '#';
                }
                else if ((s[i] - '0') >= 97 || (s[i] - '0') <= 122) {
                    lower.push_back(s[i] - '0');
                    s[i] = '#';
                }
            } else
                continue;
        }
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        int a = 0;
        int b = 0;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '#' && a < upper.size()) {
                s[i] = upper[a] + '0';
                a++;
            } else if (s[i] == '#' && b < lower.size()) {
                s[i] = lower[b] + '0';
                b++;
            }
        }
        return s;
    }
};