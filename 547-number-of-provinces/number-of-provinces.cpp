class Solution {
public:
    void check(vector<vector<int>> &isConnected, vector<bool> &vis, int i){
        vis[i] = true;
        
        for(int j=0;j<isConnected.size();j++){
            if(!vis[j] && isConnected[i][j] == 1){
                check(isConnected, vis, j);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;

        int n = isConnected.size();
        vector<bool> vis(n,false);

        int cnt = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                check(isConnected, vis, i);
            }
        }
        return cnt;
    }
};