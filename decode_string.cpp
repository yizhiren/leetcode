#define ASSERT(exp)

class Solution {
public:

    int parseInt(const string& s, int st, int ed) {
        string numstr = s.substr(st, ed-st+1);
        return stoi(numstr);
    }

    string multiString(int count, string str) {
        string repeatStr;
        for(int i=0;i<count;i++) {
            repeatStr += str;
        }
        return repeatStr;
    }

    bool isNum(char ch) {
        return (ch >= '0') && (ch <= '9');
    }

    int findRight(const string& s, int pos) {
        int len = s.length();
        int bracketCount = 0;
        while(++pos < len) {
            if(s[pos]=='['){
                bracketCount++;
            } else if(s[pos]==']'){
                bracketCount--;
            }
            if (bracketCount < 0){
                return pos;
            }
        }
        return pos;
    }

    string decodeStringAtIndex(const string& s, size_t st, size_t ed) {
        string result;
        size_t index=st;
        while(index <= ed) {
            if(isNum(s[index])){
                size_t bracketLeft = s.find("[",index);
                size_t bracketRight = findRight(s,bracketLeft);
                ASSERT(bracketLeft >= 0);
                ASSERT(bracketRight >= 0);
                int count = parseInt(s, index, bracketLeft-1);
                string strInBracket = decodeStringAtIndex(s,bracketLeft+1, bracketRight-1);
                result += multiString(count, strInBracket);
                index = bracketRight + 1;
            } else {
                result += s[index++];
            }
        }

        return result;
    }

    string decodeString(string s) {
        if(s=="")return "";
        return decodeStringAtIndex(s, 0, s.length()-1);
    }
};
