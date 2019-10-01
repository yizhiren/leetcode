class Solution {
    int index;
    string s;
public:
    int calcparentheses()
    {
        index ++;
        
        int v;
        if(isleftparentheses()){
            v = calcparentheses();
        }else{
            v = getNextNumber();
        }
        while(!isrightparentheses()){
            char op = s[index++];
            int v2;
            if(isleftparentheses()){
                v2 = calcparentheses();
            }else{
                v2=getNextNumber();
            }
            if(op=='+'){
                v+=v2;
            }else if(op=='-'){
                v-=v2;
            }
        }
        index++;
        
        return v;
    }
    
    int getNextNumber(){
        int v=0;
        while(index < s.length()){
            char c=s[index];
            if(c>='0' && c<='9'){
                v=v*10+(c-'0');
            }else{
                break;
            }
            index++;
        }
        return v;
    }
    
    
    bool isleftparentheses()
    {
        return s[index]=='(';
    }
    
    bool isrightparentheses()
    {
        return s[index]==')';
    }
    

    string mytrim(string& ss){
        string tmp;
        for(int i=0;i<ss.length();i++){
            if(ss[i] == ' '){
                continue;
            }
            tmp.append(1,ss[i]);
        }
        return tmp;
    }
    
    int calculate(string ss) {
        index=0;
        s=mytrim(ss);
        if(s.empty()){
            return 0;
        }
        //if(s[0] != '(')
        {
            s = "(" + s + ")";
        }
        
        int v=calcparentheses();
        return v;
    }
};
