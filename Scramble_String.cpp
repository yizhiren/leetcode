class Solution {
public:
    map<int,
            map<int,
                    map<int,bool>
            >
    > table;
    bool isScrambleSubstr(string& s1, int start1,
                          string& s2, int start2,
                          int len) {
        //cout << "(" << s1 << "," << s2 << ")" << endl;
        if(len <= 1) {
            return s1.substr(start1, len) == s2.substr(start2, len);
        }
        
        if(table[start1][start2].find(len) != table[start1][start2].end()) {
            return table[start1][start2][len];
        }
        
        for(int i=1;i<len;i++) {
            bool isMatch = (isScrambleSubstr(s1, start1, s2, start2, i) && isScrambleSubstr(s1, start1+i, s2, start2+i, len-i))
            || (isScrambleSubstr(s1,start1+i,s2,start2,len-i) && isScrambleSubstr(s1,start1,s2,start2+len-i,i));

            if(isMatch){
                table[start1][start2][len] = true;
                return true;
            }
        }
        
        table[start1][start2][len] = false;
        return false;
    }

    bool isScramble(string s1, string s2) {
        
        return isScrambleSubstr(s1, 0, s2, 0, (int)s1.length());
    }
};
