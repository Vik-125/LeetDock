class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return n;
        int prev = 0;
        int curr = 0;
        int cnt = 1;
        int maxi = 1;

        for (int i = 0; i < n - 1; i++) {
            curr = arr[i] - arr[i + 1];
            if (curr == 0) {
                cnt = 1;
            } else if ((curr < 0 && prev > 0) || (curr > 0 && prev < 0)) {
                cnt++;
            } else {
                cnt = 2;
            }
            maxi = max(maxi, cnt);
            prev = curr;
        }
        return maxi;
    }
};