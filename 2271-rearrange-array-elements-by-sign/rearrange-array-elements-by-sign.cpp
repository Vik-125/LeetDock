class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> po;
        vector<int> ne;
        for(auto it : nums)
        {
            if(it < 0) ne.push_back(it);
            else po.push_back(it);
        }

        int n = nums.size();
        int p = 0;
        int ni = 0;
        vector<int> ans;
        while(p < n/2 || n < n/2)
        {
            ans.push_back(po[p]);
            ans.push_back(ne[ni]);
            p++;
            ni++;
        }
        return ans;
    }
};