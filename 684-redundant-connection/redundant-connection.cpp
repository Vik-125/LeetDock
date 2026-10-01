class Solution {
public:
    int findP(int node, vector<int> &parent){
        if(node == parent[node]) return node;

        return parent[node] = findP(parent[node], parent);
    }
    void makeConn(int u, int v, vector<int> &parent){
        int ulpu = findP(u, parent);
        int ulpv = findP(v, parent);

        if(ulpu == ulpv) return;

        parent[ulpu] = ulpv;
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n+1);
        for(int i=0;i<n;i++) parent[i] = i;

        for(const auto &it : edges){
            int u = it[0];
            int v = it[1];

            if(findP(u, parent) == findP(v, parent)) return {u,v};
            makeConn(u , v, parent);
        }
        return {};
    }
};