class Solution {
public:
    int gcd(int a,int b)
    {
        return b == 0 ? a :gcd(b,a%b);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int one = count(nums.begin(),nums.end(),1);

        if(one > 0) return n - one;

        int minLen = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int g = nums[i];
            for(int j=i+1;j<n;j++)
            {
                g = gcd(g,nums[j]);
                if(g == 1)
                {
                    minLen = min(j - i + 1,minLen);
                    break;
                }
            }
        }
        return minLen == INT_MAX ? -1 : minLen - 1 + (n-1);
    }
};