
class Solution {
public:
    bool isLetter(char ch){
        return ch >= 'a' && ch <= 'z';
    }
    string decodeAtIndex(string S, int K) {
        //cout << ">> " << S << "," << K << endl;
        unsigned long long charCount = 0;
        size_t len = S.size();
        for(int i=0;i<len;i++){
            char ch = S[i];
            
            if(isLetter(ch)){
                charCount++;
                if(charCount == K){
                    return string(1,ch);
                }
                continue;
            }
            int num = ch-'0';
            unsigned long long preCount = charCount;
            charCount *= num;
            
            if(charCount < K){
                continue;
            }
            
            int smallerK = K % preCount;
            if(0==smallerK){
                smallerK = preCount;
            }
            return decodeAtIndex(S,smallerK);
        }
        
        return "";
    }
};
