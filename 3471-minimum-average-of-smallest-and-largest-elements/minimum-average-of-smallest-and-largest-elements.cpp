class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double minAvg = DBL_MAX;
        double avg;
        // int minIdx;
        // int maxInd;

        // while(nums.size() > 0)
        // {
        //     int maxi = INT_MIN;
        //     int mina = INT_MAX;
        //     for(int i=0;i<nums.size();i++)
        //     {
        //         if(maxi < nums[i]) 
        //         {
        //             maxi = nums[i];
        //             maxIdx = i;
        //         }
        //         else if(mina > nums[i])
        //         {
        //             mina = nums[i];
        //             minIdx = i;
        //         }
        //     }

        //     avg = (maxi + mina) / 2;
        //     ans =  min(ans,avg);
        // }
        int l = 0;
        int r = nums.size() - 1;
        sort(nums.begin(),nums.end());

        while(l < r)
        {
            double k = nums[l];
            double m = nums[r];
            avg = (k+m) / 2;
            minAvg = min(avg,minAvg);
            l++;
            r--;
        }
        return minAvg;
    }
};