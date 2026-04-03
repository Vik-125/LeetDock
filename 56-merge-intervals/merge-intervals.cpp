class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        ans.push_back(intervals[0]);

        int k = 0;
        for(int i=0;i<n;i++){
            if(ans[k][1] >= intervals[i][0]){
                ans[k][1] = max(intervals[i][1],ans[k][1]);
            }
            else {
                ans.push_back(intervals[i]);
                k++;
            }
        }
        return ans;
    }
};