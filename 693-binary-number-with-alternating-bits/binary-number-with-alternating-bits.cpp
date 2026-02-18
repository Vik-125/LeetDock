class Solution {
public:
    void check(int n,vector<int> &bit)
    {
        while(n > 0)
        {
            bit.push_back(n%2);
            n /= 2;
        }
        return;
    }
    bool hasAlternatingBits(int n) {
        vector<int> bit;
        
        check(n,bit);

        for(int i=0;i<bit.size()-1;i++)
        {
            if(bit[i] == bit[i+1]) return false;
        }
        return true;
    }
};