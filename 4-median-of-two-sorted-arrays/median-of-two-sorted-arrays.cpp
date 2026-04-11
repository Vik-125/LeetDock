class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size() - 1;
        int r = 0;

        while (l >= 0 && r < nums2.size()) {
            if (nums1[l] > nums2[r]) {
                swap(nums1[l], nums2[r]);
                l--;
                r++;
            } else
                break;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        nums1.insert(nums1.end(),nums2.begin(),nums2.end());

        int n = nums1.size();

        if(n % 2 != 0) return (double) nums1[n/2];
        else return (double) (nums1[n/2]+nums1[(n/2) - 1])/2;
        return 0;
    }
};