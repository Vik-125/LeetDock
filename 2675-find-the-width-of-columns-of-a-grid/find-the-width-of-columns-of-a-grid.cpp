class Solution {
public:
    int check(int num)
    {
        if(num == 0) return 1;
        int dig = 0;
        if(num < 0) dig++;
        num = abs(num);

        while(num > 0)
        {
            num /= 10;
            dig++;
        }
        return dig;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<int> ans;

        for(int j=0;j<m;j++)
        {
            int col = INT_MIN;
            int Mcol = INT_MIN;
            for(int i=0;i<n;i++)
            {
                col = check(grid[i][j]);
                Mcol = max(Mcol,col);
            }
            ans.push_back(Mcol);
        }
        return ans;
    }
};