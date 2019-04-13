#define CHECKED_STEP_IF_SUCC if(chars[s2[ed]] > 0)\
    { \
    chars[s2[ed]] --; \
    ed ++; \
    matchleft --; \
    continue; \
    }

#define ELSE_GETBACK_ST  chars[s2[st]] ++; matchleft ++; st++;

#define ELSE_MOVEON_STED st++; ed++;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.empty()){
            return true;
        }
        if(s2.empty()){
            return false;
        }
        
        size_t matchleft = s1.length();
        
        map<char, int> chars;
        for(auto &ch: s1){
            chars[ch] += 1;
        }
        
        int st=0;
        int ed=0;
        
        while(1){
            if(matchleft <= 0){
                return true;
            }
            if(ed >= s2.length()){
                return false;
            }
            if(st==ed){
                CHECKED_STEP_IF_SUCC
                
                ELSE_MOVEON_STED
                continue;
            }
            if(st < ed){
                CHECKED_STEP_IF_SUCC
                
                ELSE_GETBACK_ST
                continue;
            }
        }
        
        return true;
    }
};
