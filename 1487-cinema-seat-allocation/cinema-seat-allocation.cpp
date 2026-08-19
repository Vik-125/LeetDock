class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int result = 2*n;
        set<pair<int,int>> hash;
        unordered_map<int,int> hash2;

        for(auto it : reservedSeats){
            hash.insert({it[0],it[1]});
            hash2[it[0]]++;
        }
        for(auto it : hash2){
            int row = it.first;

            bool A = true; // 2-5
            bool B = true; // 4-7
            bool C = true; // 6-9

            for(int j = 2; j <= 5; j++)
                if(hash.count({row, j}))
                    A = false;

            for(int j = 4; j <= 7; j++)
                if(hash.count({row, j}))
                    B = false;

            for(int j = 6; j <= 9; j++)
                if(hash.count({row, j}))
                    C = false;

            if(A && C) {
                continue;
            }
            else if(A || B || C) {
                // 1 family instead of 2
                result--;
            }
            else {
                // 0 families instead of 2
                result -= 2;
            }
        }
        return result;
    }
};