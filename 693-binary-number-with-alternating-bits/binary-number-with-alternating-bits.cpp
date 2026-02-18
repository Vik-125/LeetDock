class Solution {
public:
    bool hasAlternatingBits(int n) {
        int k = -1;
        while(n > 0)
        {
            int m = n%2;
            n /= 2;
            if(k == m) return false;
            k = m;
        }
        return true;
    }
};