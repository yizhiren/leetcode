class Solution {
public:
    bool checkValidString(string s) {
        if(s.empty()){
            return true;
        }

        int lo=0;
        int hi=0;
        for(auto ch:s){
            lo += ch=='('?1:-1;
            lo=max(0,lo);
            
            hi += ch!=')'?1:-1;
            if(hi<0)return false;
        }
        return lo==0;

    }
};
