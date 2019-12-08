class Solution {
public:
    int getSum(int a, int b) {
        if(a==0){
            return b;
        }
        int doubleBit = a&b;
        int mergeBit = a^b;
        return getSum(unsigned(doubleBit) << 1, mergeBit);
    }
};
