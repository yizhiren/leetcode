class Solution {
public:
    int uniqueLetterString(string S) {
        if(S.empty()){
            return 0;
        }
        size_t len = S.length();
        //cout << "len:" << len << endl;
        unsigned long long sum = 0;
        
        {
            map<char,int> count;
            int uniqCount = 0;
            unsigned long long countOfStartWithIndex = 0;
            for(int j=0;j<len;j++){
                char ch = S[j];
                count[ch] ++;
                if(count[ch] == 1){
                    uniqCount++;
                }else if(count[ch] == 2){
                    uniqCount--;
                }
                countOfStartWithIndex += uniqCount;
            }
            //cout << "countOfStartWithIndex=" << countOfStartWithIndex << endl;
            sum += countOfStartWithIndex;
            
            auto findNextChar = [&](int index, char ch){
                if(index >= len-1){
                    return int(len);
                }
                for(index=index+1;index<len;index++){
                    if(S[index] == ch){
                        break;
                    }
                }
                
                return index;
            };
            
            for(int j=0;j<len;j++){
                char ch = S[j];
                count[ch] --;
                int next1 = findNextChar(j,ch);
                int next2 = findNextChar(next1,ch);
                countOfStartWithIndex = countOfStartWithIndex - (next1-j) + (next2-next1);
                //cout << "countOfStartWithIndex=" << countOfStartWithIndex << endl;
                sum += countOfStartWithIndex;
            }
        }

        //const unsigned long long modulo = 1000000007;
        //return sum % modulo;
        return sum;
    }
};
