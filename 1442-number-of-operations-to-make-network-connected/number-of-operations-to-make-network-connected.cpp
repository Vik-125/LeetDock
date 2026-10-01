class Solution {
public:
    int findP(int node, vector<int> &parent){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findP(parent[node], parent);
    }
    void makeConnection(int u, int v, vector<int> &parent, vector<int> &rank){
        int upu = findP(u, parent);
        int upv = findP(v, parent);

        if(upu == upv) return;
        else if(rank[upu] < rank[upv]){
            parent[upu] = upv;
        }
        else if(rank[upu] > rank[upv]){
            parent[upv] = upu;
        }
        else{
            parent[upu] = upv;
            rank[upv]++;
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        vector<int> rank(n,0);

        int multiConnection = 0;
        for(const auto &it : connections){
            int u = it[0];
            int v = it[1];
            if(findP(u, parent) == findP(v, parent)) multiConnection++;
            makeConnection(u, v, parent, rank);
        }
        if(connections.size()  < n-1) return -1;

        int k = 0;
        
        for(int i=0;i<n;i++){
            if(parent[i] == i) k++;
        }
        return k-1;
    }
};