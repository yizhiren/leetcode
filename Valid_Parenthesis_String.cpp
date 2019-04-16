class Solution {
public:
    bool checkValidString(string s) {
        if(s.empty()){
            return true;
        }
        size_t len = s.length();
        int right_low=0; // 最少几个）
        int right_high=0;//最多几个）
        for(int i=0;i<len;i++){
            if('(' == s[i]){
                right_low ++;
                right_high ++;
            }else if(')' == s[i]){
                if(right_low <= 1){
                    right_low = 0;
                } else {
                    right_low --;
                }
                if(--right_high < 0){
                     return false;
                }
            }else{
                if(right_low <= 1){
                    right_low = 0;
                } else {
                    right_low --;
                }
                right_high ++;
            }
        }
        return right_low==0;
    }
};
