class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> hash1(nums1.begin(),nums1.end());
        unordered_set<int> hash2(nums2.begin(),nums2.end());
        
        for(auto key : hash1)
        {
            if(hash2.count(key)) ans.push_back(key);
        }
        return ans;
    }
};