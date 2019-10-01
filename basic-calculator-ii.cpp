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
            if(isJiaJian(s[i])){
                int v1 = getNextNumber();
                if (expr.empty() || isJiaJian(expr.top())){
                    pushNumber(v1);
                    expr.push(s[i]);
                    continue;
                }
                int op = popChar();
                int v2 = getNextNumber();
                int v3 = v1 * v2;
                if (op=='/'){
                    v3 = v1/v2;
                }
                pushNumber(v3);
                i++;//抵消i--
                
                //cout << "v1=" << v1 << ",v2=" << v2 << ",v3=" << v3 << endl;
            } else {
                expr.push(s[i]);
            }
        }

        while(!expr.empty()){
            int v1 = getNextNumber();
            if (expr.empty() || isJiaJian(expr.top())){
                pushNumber(v1);
                break;
            }
            int op = popChar();
            int v2 = getNextNumber();
            int v3 = v1 * v2;
            if (op=='/'){
                v3 = v1/v2;
            }
            pushNumber(v3);
        }
        
        while(!expr.empty()){
            int v1 = getNextNumber();
            if (expr.empty()){
                pushNumber(v1);
                break;
            }
            int op = popChar();
            int v2 = getNextNumber();
            int v3 = v1 + v2;
            if (op=='-'){
                v3 = v1-v2;
            }
            pushNumber(v3);
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
    
    
    bool isJiaJian(char ch)
    {
        return ch=='+' || ch == '-';
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
        
        return walkS(s);
    }
};
