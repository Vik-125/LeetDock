class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end(), greater<int>());  // Sort descending

            int first = stones[0];
            int second = stones[1];

            stones.erase(stones.begin());       // Remove first
            stones.erase(stones.begin());       // Remove second (now at index 0)

            if (first != second) {
                stones.push_back(first - second);  // Add the difference
            }
        }

        return stones.empty() ? 0 : stones[0];

    }
};