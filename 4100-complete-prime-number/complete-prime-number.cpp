class Solution {
public:
    bool check(int n){        
        if(n <= 1) return false;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i == 0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        if(num <= 0) return false;

        int n = num;

        if(!check(n%10)) return false;
        while(n > 0)
        {
            if(!check(n)) return false;
            n /= 10;
        }
        int pow10 = 1;
        while (pow10 <= num) {
            int suffix = num % pow10;
            if (suffix > 0 && !check(suffix)) return false;
            pow10 *= 10;
        }
        return true;
    }
};