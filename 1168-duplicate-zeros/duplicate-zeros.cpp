class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();

        vector<int> temp = arr;
        int j = 0;
        for(int i=0;i<n;i++){
            if(temp [i] == 0 && j < n){
                arr[j++] = 0;
                if(j < n){
                    arr[j++] = 0;
                }       
                else return;         
            }
            else if(temp[i] != 0 && j < n) arr[j++] = temp[i];
            else return;
        }
        return;
    }
};