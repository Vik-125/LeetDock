class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> namo1(nums1.begin(), nums1.end());
        unordered_set<int> namo2(nums2.begin(), nums2.end());


        int count1 = 0;
        for (int num : nums1) {
            if (namo2.count(num)) count1++;
        }
        int count2 = 0;
        for (int num : nums2) {
            if (namo1.count(num)) count2++;
        }

        return {count1,count2};
    }
};