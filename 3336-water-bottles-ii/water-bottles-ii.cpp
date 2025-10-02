class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int ans = 0;
        while(numBottles > 0)
        {
            ans += numBottles;
            empty += numBottles;
            numBottles = 0;
            while(empty >= numExchange)
            {
                numBottles++;
                empty -= numExchange;
                numExchange++;
            }
        }
        return ans;
    }
};