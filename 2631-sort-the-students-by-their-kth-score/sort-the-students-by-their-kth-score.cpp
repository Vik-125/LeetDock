class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(score[j][k] < score[j+1][k]) swap(score[j],score[j+1]);
            }
        }
        return score;
    }
};