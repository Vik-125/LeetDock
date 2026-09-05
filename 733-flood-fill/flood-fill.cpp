class Solution {
public:
    void colorCube(vector<vector<int>> &image, int sr, int sc, int r, int c, int color, int pColor){
        int dcol[] = {1,0,-1,0};
        int drow[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr = sr + drow[i];
            int nc = sc + dcol[i];

            if(nr < r && nr >= 0 && nc < c && nc >= 0 && image[nr][nc] == pColor){
                image[nr][nc] = color;
                colorCube(image, nr, nc, r, c, color, pColor);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int pColor = image[sr][sc];
        if (pColor == color) return image;
        
        image[sr][sc] = color;
        colorCube(image, sr, sc, n, m, color, pColor);
        return image;
    }
};