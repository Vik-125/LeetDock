class Solution {
public:
    int findMax(vector<vector<int>>& mat, int n, int m, int mid) {
        int maxEle = -1;
        int maxIdx = -1;
        for (int i = 0; i < n; i++) {
            if(mat[i][mid] > maxEle){
                maxEle = max(mat[i][mid], maxEle);
                maxIdx = i;
            }
        }
        return maxIdx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> peak;
        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int row = findMax(mat, n, m, mid);

            int left = mid-1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid+1 < m ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row,mid};
            else if (mat[row][mid] > left) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return {};
    }
};