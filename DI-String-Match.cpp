class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.length();
        vector<int> result;
        result.resize(len+1);
        
        int low=0;
        int high = len;
        
        int i=0;
        for(;i<len;i++){
            if(S[i]=='I'){
                result[i] = low++;
            }
            if(S[i]=='D'){
                result[i] = high--;
            }
        }
        result[i] = low;

        return result;
    }
};
