class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cLasers = 0;
        int pLasers = 0;
        int ans = 0;
        for(int i=0;i<bank.size();i++)
        {
            cLasers = 0;
            for(auto it : bank[i])
            {
                if(it == '1') cLasers++;
            }
            if(cLasers == 0) cLasers = pLasers;
            else 
            {
                ans += (cLasers * pLasers);
                pLasers = cLasers;
            }
        }
        return ans;
    }
};