class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));

        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;

        int element = 1;

        while(top <= bottom && left <= right){
            for(int i=left;i<=right;i++){
                matrix[top][i] = element;
                element++;
            }
            top++;

            for(int j=top;j<=bottom;j++){
                matrix[j][right] = element;
                element++;
            }
            right--;

            for(int k=right;k>=left;k--){
                matrix[bottom][k] = element;
                element++;
            }
            bottom--;

            for(int l=bottom;l>=top;l--){
                matrix[l][left] = element;
                element++;
            }
            left++;
        }
        return matrix;
    }
};