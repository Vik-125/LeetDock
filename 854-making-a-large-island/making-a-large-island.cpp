class Solution {
    class DisjoinSet {
    public:
        vector<int> parent, rank, size;
        DisjoinSet(int n) {
            parent.resize(n);
            rank.assign(n, 0);
            size.assign(n, 1);
            for (int i = 0; i < n; i++)
                parent[i] = i;

        }
        int findP(int node) {
            if (parent[node] == node) {
                return node;
            }
            return parent[node] = findP(parent[node]);
        }
        void makeConnection(int u, int v) {
            int ulpu = findP(u);
            int ulpv = findP(v);

            if (ulpu == ulpv)
                return;

            else if (rank[ulpu] > rank[ulpv]) {
                parent[ulpv] = ulpu;
                size[ulpu] += size[ulpv];
            }

            else if (rank[ulpv] > rank[ulpu]) {
                parent[ulpu] = ulpv;
                size[ulpv] += size[ulpu];
            } 
            else {
                parent[ulpu] = ulpv;
                rank[ulpv]++;
                size[ulpv]+=size[ulpu];
            }
            return;
        }
} ;
private : 
bool isValid(int nrow, int ncol, int row, int col){
    return (nrow < row && ncol < col && nrow >= 0 && ncol >= 0);
}
public : 
int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DisjoinSet ds(n * m);

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 0) continue;
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, -1, 0, 1};

                for(int i=0;i<4;i++){
                    int nrow = row + delr[i];
                    int ncol = col + delc[i];

                    if(isValid(nrow, ncol, n, n) && grid[nrow][ncol] == 1){
                        int node = n * row + col;
                        int adjNode = n* nrow + ncol;

                        ds.makeConnection(node, adjNode);
                    }
                }
            }
        }
        int maxSize = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 1) continue;
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, -1, 0, 1};

                set<int> components;
                for(int i=0;i<4;i++){
                    int nrow = row + delr[i];
                    int ncol = col + delc[i];

                    if(isValid(nrow, ncol, n, n) && grid[nrow][ncol] == 1){
                        components.insert(ds.findP(nrow * n + ncol));
                    }
                }
                int length = 0;
                for(auto it : components){
                   length += ds.size[it];
                }
                maxSize = max(length + 1, maxSize);
            }
        }
        for(int i=0;i<n*m;i++){
            maxSize = max(maxSize, ds.size[ds.findP(i)]);
        }
        return maxSize;
    }
};