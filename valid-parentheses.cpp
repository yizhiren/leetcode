class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        map<char,char> charmap;
        charmap['('] = ')';
        charmap['['] = ']';
        charmap['{'] = '}';

        for(int i=0,len=s.length();i<len;i++){
            if(charmap.find(s[i]) != charmap.end()){
                brackets.push(s[i]);
            }else{
                if(0==brackets.size()) return false;
                char left=brackets.top();brackets.pop();
                if(charmap[left] !=s[i])return false;
            }
        }
        return brackets.empty();
    }
};
