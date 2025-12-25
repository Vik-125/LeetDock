class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(),happiness.end(),greater<int>());

        int n = happiness.size();
        for(int i=0;i<k;i++)
        {
            long long val =  happiness[i] - i;
            if(val >= 0)
            {
                ans += val;
            }
            else return ans;
        }
        return ans;
    }
};