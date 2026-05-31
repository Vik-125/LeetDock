class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());

        for(const int& it : asteroids){
            if(mass < it) return false;
            else mass += it;
        }
        
        return true;
    }
};