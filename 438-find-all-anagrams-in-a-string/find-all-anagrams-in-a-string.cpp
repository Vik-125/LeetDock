class Solution {
public:
    bool check(unordered_map<char,int> &hashp,unordered_map<char,int> &hashs){
        for(auto it : hashp){
            if(hashs[it.first] != it.second) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> hashp;
        unordered_map<char,int> hashs;

        for(auto it : p){
            hashp[it]++;
        } 
        vector<int> ans;

        int l = 0;
        int r = 0;
        int pSize = p.size();

        while(r <= s.size()){
            if(r-l < pSize){
                hashs[s[r]]++;
                r++;
            }
            else{
                if(check(hashs,hashp)) ans.push_back(l);
                hashs[s[l]]--;
                l++;
            }
            
        }
        return ans;
    }
};