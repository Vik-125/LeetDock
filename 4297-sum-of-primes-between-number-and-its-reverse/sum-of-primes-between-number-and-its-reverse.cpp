class Solution {
public:
    bool primo(int i){
        if(i == 1) return false;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j == 0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        if(n >= 1 && n <= 9){
            if(primo(n)) return n;
            else return 0;
        }
        int sum = 0;
        int revNum = 0;
        int temp = n;

        while(temp > 0){
            int dig = temp%10;
            revNum = (revNum*10) + dig;
            temp /= 10;
        }

        int mini = min(revNum,n);
        int maxi = max(revNum,n);

        int i = mini;
        while(i <= maxi){
            if(primo(i)){ 
                sum += i;
                cout << i << " ";
            }
            
            i++;
        }
        return sum;
    }
};