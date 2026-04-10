class Solution {
public:
    int check(int cnt,vector<int> & bloomDay,int k,int mid,int m){
        int temp = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] > mid) temp = 0;
            else{
                temp++;
                if(temp == k){
                    temp = 0;
                    cnt++;
                }
            }
        }
        return cnt >= m ? 1 : 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(low <= high){
            int mid = (low + high)/2;

            int cnt = 0;
            
            if(check(cnt,bloomDay,k,mid,m) == 1){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
