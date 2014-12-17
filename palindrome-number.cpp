class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int xcopy=x;
        int y=0;
        while(xcopy){
            y=y*10+xcopy%10;
            xcopy=xcopy/10;
        }
        return x==y;
    }
};
