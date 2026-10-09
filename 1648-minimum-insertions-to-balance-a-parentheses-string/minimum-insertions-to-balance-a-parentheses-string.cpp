class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int needed_right = 0;

        for (char c : s) {
            if (c == '(') {
                // Each '(' needs two ')'
                needed_right += 2;

                // If needed_right is odd, it means we have a single ')' 
                // waiting to match a previous '('. We must insert one ')' 
                // to make it consecutive '))'.
                if (needed_right % 2 != 0) {
                    ans++;          // Insert one ')'
                    needed_right--; // We used one ')' insertion
                }
            } else { // c == ')'
                needed_right--;

                // If needed_right becomes negative, we encountered a ')' 
                // without a corresponding '('. Insert '(' to balance it.
                if (needed_right < 0) {
                    ans++;             // Insert '('
                    needed_right += 2; // '(' needs two ')' (one of which is current 'c')
                }
            }
        }

        // Add remaining required ')' for unmatched '('
        return ans + needed_right;
    }
};