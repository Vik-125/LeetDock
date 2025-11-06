class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indices;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == x) indices.push_back(i);
        }


        vector<int> ans;
        for(int q : queries) {
            if(q <= indices.size()) {
                ans.push_back(indices[q - 1]); // 1-based query
            } else {
                ans.push_back(-1); // not enough occurrences
            }
        }
        return ans;
    }
};