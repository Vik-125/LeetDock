class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;
        int add_count = 0;

        for (char c : s) {
            if (c == '(') {
                open_needed++;
            } else {
                if (open_needed > 0) {
                    open_needed--; // Match with an existing '('
                } else {
                    add_count++;   // Need an extra '('
                }
            }
        }

        return add_count + open_needed;
    }
};