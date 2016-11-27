

class Solution {
public:
    int getBytesLen(bitset<8>& bits){
        if(!bits[7]){
            return 1;
        }
        if(bits[7] && bits[6] && !bits[5]){
            return 2;
        }
        if(bits[7] && bits[6] && bits[5] && !bits[4]){
            return 3;
        }
        if(bits[7] && bits[6] && bits[5] && bits[4] && !bits[3]){
            return 4;
        }
        return 0; 
    }
    bool validUtf8(vector<int>& data) {
        vector<int>::iterator iter = data.begin();
        
        while(iter != data.end()){
            bitset<8> bits(*iter);
            int byteLen = getBytesLen(bits);//printf("bytelen:%d\n",byteLen);
            switch(byteLen){
            case 1:
                break;
            case 2:
            case 3:
            case 4:
            {
                vector<int>::iterator tmpiter = iter;
                for(int i=1;i<byteLen;i++){
                    tmpiter ++;
                    if(tmpiter == data.end()){
                        return false;
                    }
                    bitset<8> tmpbits(*tmpiter);
                    if(!tmpbits[7] || tmpbits[6]){
                        return false;
                    }
                }
                iter = tmpiter;
                break;   
            }
            default:
                return false;
            }
            
            iter++;
        }
        
        return true;
        
    }
};
