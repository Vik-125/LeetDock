class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int costt = 0;
        sort(cost.begin(),cost.end());
        int j=1;

        for(int i=n-1;i>=0;i--){
            if(j % 3 == 0) {
                j++;
                continue;
            }
            else costt += cost[i];
            j++;
        }
        return costt;
    }
};