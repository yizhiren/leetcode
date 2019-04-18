class Solution {
public:
    int compress(vector<char>& chars) {
        int len  = chars.size();
        int writePlace = 0;
        int readPlace = 0;
        
        while(readPlace < len){
            char ch = chars[readPlace];
            int chStart = readPlace;
            while(++readPlace < len){
                if(chars[readPlace] != ch){
                    break;
                }
            }
            int len = readPlace-chStart;
            chars[writePlace++] = ch;
            
            if(len==1){
                // nothing
            }else if(len < 10){
                chars[writePlace++] = len+'0';
            }else if(len < 100){
                chars[writePlace+1] = len % 10 +'0';
                chars[writePlace] = len / 10 +'0';
                writePlace += 2;
            } else if(len < 1000){
                chars[writePlace+2] = len % 10 +'0';
                len = len/10;
                chars[writePlace+1] = len % 10 +'0';
                len = len/10;
                chars[writePlace] = len % 10 +'0';
                writePlace += 3;
            } else {
                // max 1000, so here len==1000
                chars[writePlace++]='1';
                chars[writePlace++]='0';
                chars[writePlace++]='0';
                chars[writePlace++]='0';
            }
        }
        
        auto iter = chars.begin();
        advance(iter,writePlace);
        chars.erase(iter, chars.end());
        return writePlace;
    }
};
