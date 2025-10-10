class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> hash;

        for(auto it : sentence)
        {
            hash[it]++;
        }

        return (hash.size() == 26);
    }
};