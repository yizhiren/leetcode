class Solution {
public:
    int palindromicCount(const string& s, int mid){
        return palindromicCount(s, mid,mid);
    }
    int palindromicCount(const string& s, int midleft, int midright){
        int len=s.length();
        int i=0;
        int count = 0;
        while(midleft-i >= 0 && midright+i <len) {
            if(s[midleft-i] == s[midright+i]){
                count ++;
                i++;
            }else {
                break;
            } 
        }
        
        return count;
    }
    int countSubstrings(string s) {
        int len=s.length();
        int count = 0;
        for(int i=0;i<len;i++){
            count += palindromicCount(s,i);
        }
        for(int i=0;i<len-1;i++){
            count += palindromicCount(s,i,i+1);
        }
        
        return count;
    }
};
