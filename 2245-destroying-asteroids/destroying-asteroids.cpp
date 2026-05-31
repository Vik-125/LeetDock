class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        int n = asteroids.size();
        bool flag = true;
        sort(asteroids.begin(),asteroids.end());

        for(auto it : asteroids){
            if(mass > it || mass == it) mass += it;
            else flag = false;
        }
        
        return flag;
    }
};