class Solution {
public:
    void perm(vector<int> & nums,vector<vector<int>> & ans,vector<int> &vis,vector<int> &ds){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<vis.size();i++){
            if(vis[i] == 1){
                ds.push_back(nums[i]);
                vis[i] = 0;
                perm(nums,ans,vis,ds);
                ds.pop_back();
                vis[i] = 1;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 1){
            ans.push_back(nums);
            return ans;
        }
        vector<int> vis(n);
        for(int i=0;i<n;i++) vis[i] = 1;
        vector<int> ds;

        perm(nums,ans,vis,ds);
        return ans;
    }
};