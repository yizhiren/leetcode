char result[501];

class Solution {
public:
    string reorganizeString(string S) {
        if(S.length() <= 1){
            return S;
        }
        
        size_t len = S.length();
        map<char,int> chars;
        for(int i=0;i<len;i++){
            chars[S[i]] += 1;
        }
        vector< pair<char,int> > pairs;
        copy(chars.begin(),chars.end(),back_inserter< vector< pair<char,int> > >(pairs));
        sort(pairs.begin(),pairs.end(),[](const auto& a, const auto& b){
            return a.second > b.second;
        });
        
        memset(result,0,len+1);
        int cur = 0;
        for(int i=0;i<pairs.size();i++){
            auto& pr = pairs[i];
            while(pr.second > 0){
                while(result[cur] != '\0'){
                    cur = (cur+1)% len;
                }
                result[cur] = pr.first;
                pr.second -= 1;
                if(pr.second > 0) {
                    cur = (cur+2) % len;
                } else {
                    cur = (cur+1) % len;
                }
            }
            
        }
        for(int i=0;i<len;i++){
            if(result[i] == result[i+1]){
                return "";
            }
        }
        return result;
    }
    


    
};
