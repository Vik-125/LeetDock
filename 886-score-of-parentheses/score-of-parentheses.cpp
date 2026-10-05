class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int depth = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // Moving one level deeper
                depth++;
            } else {
                // Moving one level up
                depth--;
                
                // If it forms the core "()", calculate its nested value
                if (s[i - 1] == '(') {
                    ans += (1 << depth); // equivalent to 2^depth
                }
            }
        }

        return ans;
    }
};