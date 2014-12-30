class Solution {
    string one;
    vector<string>  result;
    int len;
    void makeString(int x,int y){
        if(x < y) return;
        if(x==len && y==len){
            result.push_back(one);
            return;
        }
        if(x<len){
            one[x+y]='(';
            makeString(x+1,y);
        }
        if(y<len){
            one[x+y]=')';
            makeString(x,y+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        len=n;
        one.resize(2*len);
        makeString(0,0);
        return result;
    }
};
