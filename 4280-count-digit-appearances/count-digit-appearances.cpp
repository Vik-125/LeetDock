class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        for(auto it : nums){
            while(it > 0){
                int dig = it%10;
                if(dig == digit) cnt++;
                it /= 10;
            }
        }
        return cnt;
    }
};