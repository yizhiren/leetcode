// using stack
class Solution {
    stack<char> expr;
public:
    void pushNumber(int num) {
        bool isNeg = false;
        if (num < 0) {
            isNeg = true;
            num = -num;
        }
        do{
            char v = num % 10;
            num = num / 10;
            expr.push(v+'0');
        }while(num);
        
        if(isNeg){
            expr.push('-');
        }
    }
    int walkS(const string& s) {
        int len = s.length();
        for(int i=len-1;i>=0;i--) {
            if(isleftparentheses(s[i])){
                int v1 = getNextNumber();
                if (isrightparentheses(expr.top())){
                    popChar();
                    pushNumber(v1);
                    continue;
                }
                int op = popChar();
                int v2 = getNextNumber();
                int v3 = v1+v2;
                if (op=='-'){
                    v3 = v1-v2;
                }
                if (isrightparentheses(expr.top())){
                    popChar();
                    pushNumber(v3);
                } else {
                    pushNumber(v3);
                    i++;//抵消i--
                }
                
                //cout << "v1=" << v1 << ",v2=" << v2 << ",v3=" << v3 << endl;
            } else {
                expr.push(s[i]);
            }
        }
        return getNextNumber();
    }
    
    
    char popChar() {
        char ch = expr.top();
        expr.pop();
        return ch;
    }
    
    int getNextNumber(){
        int value = 0;
        bool isNeg = false;
        if(!expr.empty() && expr.top()=='-'){
            isNeg = true;
            expr.pop();
        }
        while(!expr.empty() && isnumber(expr.top())) {
            char tmp = expr.top();
            value = 10 * value + (tmp-'0');
            expr.pop();
        }
        if (isNeg){
            value = -value;
        }
        return value;
    }
  
    bool isnumber(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    

    bool isleftparentheses(char ch)
    {
        return ch=='(';
    }
    bool isrightparentheses(char ch)
    {
        return ch==')';
    }
    
    string mytrim(string& ss){
        string tmp;
        
        for (auto ch : ss)
        {
            if(ch == ' '){
                continue;
            }
            tmp.append(1,ch);
        }
        
        return tmp;
    }
    
    int calculate(string ss) {
        stack<char>().swap(expr);
        string s=mytrim(ss);
        
        if(s.empty()){
            return 0;
        }
        
        //if(s[0] != '(')
        {
            s = "(" + s + ")";
        }
        
        int v=walkS(s);
        return v;
    }
};
