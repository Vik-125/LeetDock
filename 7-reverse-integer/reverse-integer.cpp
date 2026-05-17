class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        long long y = x;
        int flag = 0;
        if(x < 0){
            y = y * -1;
            flag = 1;
        }
        while(y > 0){
            int dig = y%10;
            rev = rev*10 + dig;
            y /= 10;
        }
        long long lim = pow(2,31);
        if(rev < -lim || rev > lim-1) return 0;
        if(flag == 1) return 0-rev;
        return rev;
    }
};