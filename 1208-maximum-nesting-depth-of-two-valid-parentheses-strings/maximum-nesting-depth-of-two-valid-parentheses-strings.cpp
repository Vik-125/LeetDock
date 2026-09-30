class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> sta;
        stack<char> stb;
        int deptha = 0;
        int depthb = 0;
        int n = seq.size();
        vector<int> result;

        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                if(deptha > depthb){
                    depthb++;
                    stb.push('(');
                    result.push_back(1);
                }
                else{
                    deptha++;
                    sta.push('(');
                    result.push_back(0);
                }
            }
            else {
                if(deptha < depthb && !stb.empty() && stb.top() =='('){
                    stb.pop();
                    depthb--;
                    result.push_back(1);
                }
                else if(deptha >= depthb && !sta.empty() && sta.top() =='('){
                    sta.pop();
                    deptha--;
                    result.push_back(0);
                }
            }
        }
        return result;
    }
};