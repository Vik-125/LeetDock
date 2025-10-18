class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int minIdx = 0;
        int maxIdx = 0;
        int Mele = INT_MIN;
        int mele = INT_MAX;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i] > Mele)
            {
                Mele = nums[i];
                maxIdx = i;
            }
            if(nums[i] < mele)
            {
                mele = nums[i];
                minIdx = i;
            }
        }

        // if((minIdx < n/2 && maxIdx < n/2)) return max(minIdx,maxIdx) + 1;
        // else if((minIdx > n/2 && maxIdx > n/2)) return n - max(minIdx,maxIdx) + 1;
        // else
        // {
        //     if (minIdx > maxIdx) swap(minIdx, maxIdx);
        //     int both = (minIdx + 1) + (n - maxIdx);
        //     return both;
        // }
        // return -1;
        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        int left = max(minIdx,maxIdx) + 1;
        int right = n - min(minIdx,maxIdx);
        int both = (minIdx + 1) + (n - maxIdx);

        return min({left,right,both});
    }
};