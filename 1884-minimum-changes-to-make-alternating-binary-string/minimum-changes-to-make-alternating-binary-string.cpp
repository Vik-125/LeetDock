class Solution {
public:
    int minOperations(string s) {
        bool z = 0;
        int cnt = 0;
        for(auto it : s)
        {
            if(it != z + '0') cnt++;
            z = !z;
        }
        int maxi = 0;

        z = 1;
        for(auto it : s)
        {
            if(it != z + '0') maxi++;
            z = !z;
        }
        return min(maxi,cnt);
    }
};