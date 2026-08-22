class Solution {
public:
    bool checkDivisibility(int n) {
        int pro = 1;
        int sum = 0;
        int m = n;

        while(m > 0){
            int dig = m%10;
            sum += dig;
            pro *= dig;
            m /= 10;
        }
        sum += pro;
        return n % sum == 0? true : false; 
    }
};