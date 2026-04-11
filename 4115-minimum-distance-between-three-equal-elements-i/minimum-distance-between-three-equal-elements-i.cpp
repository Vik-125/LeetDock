class Solution {
public:
int check(vector<int> arr){
    return (abs(arr[0] - arr[1]) + abs(arr[1] - arr[2]) + abs(arr[0] - arr[2]));
}
    int minimumDistance(vector<int>& nums) {
        int dist = INT_MAX;
        unordered_map<int , vector<int>> hash;

        for(int i=0;i<nums.size();i++){
            hash[nums[i]].push_back(i);

            if(hash[nums[i]].size() >= 3){
                if(hash[nums[i]].size() > 3) hash[nums[i]].erase(hash[nums[i]].begin());
                dist = min(dist,check(hash[nums[i]]));
            }
        }
        return dist == INT_MAX ? -1 : dist;
    }
};