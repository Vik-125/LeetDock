class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> maxHeap;

        for(auto it : nums) maxHeap.push(it);

        for(int i=0;i<n;i++){
            if(i+1 == k){
                return maxHeap.top();
            }
            maxHeap.pop();
        }
        return 0;
    }
};