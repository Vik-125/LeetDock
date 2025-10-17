class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].begin(),grid[i].end());
        }
        int m = grid.size();
        int n = grid[0].size();
        for(int col = n-1;col >=0 ; col--)
        {
            int maxval = INT_MIN;
            for(int row = 0;row<m;row++)
            {
                maxval = max(maxval,grid[row][col]);
            }
            ans += maxval;
        }
        return ans;
    }
};