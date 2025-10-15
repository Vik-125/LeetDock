class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>& image ,vector<vector<int>>& newMatrix,int iniColor,int color,int deltaRow[],int deltaCol[])
    {
        newMatrix[sr][sc] = color;

        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++)
        {
            int nRow = sr + deltaRow[i];
            int nCol = sc + deltaCol[i];
            if(nRow < n && nRow >=0 && nCol < m && nCol >= 0 && newMatrix[nRow][nCol] == iniColor && newMatrix[nRow][nCol] != color)
            {
                dfs(nRow,nCol,image,newMatrix,iniColor,color,deltaRow,deltaCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> newMatrix = image;
        int deltaRow[] = {-1,0,1,0};
        int deltaCol[] = {0,-1,0,1};

        dfs(sr,sc,image,newMatrix,iniColor,color,deltaRow,deltaCol);

        return newMatrix;
    }
};