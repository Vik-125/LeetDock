class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices == 0 && cheeseSlices == 0) return {0,0};
        if(tomatoSlices % 2 != 0) return {};
        int x;
        int y;

        for(int i=0;i<cheeseSlices;i++){
            y = cheeseSlices - i;
            if(((4*i) + (2*y)) == tomatoSlices && (i + y) == cheeseSlices) return {i,y};
        }
        return {};
    }
};