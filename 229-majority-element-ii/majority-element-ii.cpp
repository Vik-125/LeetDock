class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int ele1=0,ele2=0;
        int c1=0,c2=0;

        for(auto it : nums){
            if(c1 == 0 && ele2 != it){
                ele1 = it;
                c1++;
            }
            else if(c2 == 0 && ele1 != it){
                ele2 = it;
                c2++;
            }

            else if(ele1 == it) c1++;
            else if(ele2 == it) c2++;

            else {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        cout << ele1 << " " << ele2;
        for(auto it : nums){
            if(it == ele1) c1++;
            else if(it == ele2) c2++;
        }
        if(c1 > (n/3) && c2 > (n/3)) return {ele1,ele2};
        if(c1 > (n/3)) return{ele1};
        if(c2 > (n/3)) return{ele2};
        else return {};
    }
};