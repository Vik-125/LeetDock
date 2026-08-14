class Solution {
public:
    bool find(vector<int>& nums, int i, int last, bool turn, int firstScore, int secondScore){
        if(i > last){
            cout << firstScore << " " << secondScore << endl;
            return firstScore >= secondScore;
        }
        if(turn){
            return (find(nums, i+1, last, !turn, firstScore+nums[i], secondScore) || find(nums, i, last-1, !turn, firstScore + nums[last], secondScore));
        }
        else{
            return ((find(nums, i+1, last, !turn, firstScore, secondScore + nums[i])) && (find(nums, i, last-1, !turn, firstScore, secondScore + nums[last])));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int turn = 1;
        int firstScore = 0;
        int secondScore = 0;
        int n = nums.size();

        return find(nums, 0, n-1, turn, firstScore, secondScore);
    }
};
