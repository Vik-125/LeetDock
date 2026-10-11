class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        long long y = x;
        while(y > 0){
            long long i = y % 10;
            rev = rev*10 + i;
            y /= 10;
        }
        return rev == x;
    }
};