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
//////////////////////
class Solution {
public:

    vector<string> generateParenthesis(int n) {
        if(n==0){
            return vector<string>();
        }
        if(n==1){
            return vector<string>{"()"};
        }
        
        const string pr = "()";
        
        set<string> pre_level;
        pre_level.insert("()");
        
        for(int i=1;i<n;i++){
            set<string> level;
            for(auto &str: pre_level){
                int strlen = str.length();
                for(int j=0;j<strlen;j++){
                    level.insert(str.substr(0,j)+pr+str.substr(j));
                }
                level.insert(str + pr);
            }
            pre_level.swap(level);
        }
        return vector<string>(pre_level.begin(),pre_level.end());
    }
};
