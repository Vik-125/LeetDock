class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalK = (long long)k1 + k2;
        
        // Count frequencies of each absolute difference
        vector<long long> count(100001, 0);
        long long maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            count[d]++;
            maxDiff = max(maxDiff, (long long)d);
        }
        
        // Greedily reduce the largest differences
        for (long long d = maxDiff; d > 0 && totalK > 0; --d) {
            if (count[d] == 0) continue;
            
            long long take = min(count[d], totalK);
            count[d] -= take;
            count[d - 1] += take;
            totalK -= take;
        }
        
        // Calculate the final minimum sum of squared differences
        long long result = 0;
        for (long long d = 1; d <= maxDiff; ++d) {
            if (count[d] > 0) {
                result += count[d] * d * d;
            }
        }
        
        return result;
    }
};