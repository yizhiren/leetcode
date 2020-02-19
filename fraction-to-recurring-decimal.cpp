class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator==0 || numerator==0){
            return "0";
        }
        unordered_map<long long, int> tag;
        long long remain = 0;
        string result;
        
        if((numerator<0) ^ (denominator<0)){
            result += "-";
        }
        
        long long x = labs(static_cast<long long>(numerator));
        long long y = labs(static_cast<long long>(denominator));
        
        result += to_string(x/y);
        remain = x % y;
        
        if(remain==0){
            return result;
        }else {
            result += ".";
        }
        
        while(remain != 0){
            if(tag.find(remain) != tag.end()){
                result.insert(tag[remain],"(");
                result+=")";
                break;
            }
            tag[remain] = result.size();
            remain *= 10;
            result += to_string(remain/y);
            remain = remain % y;
        }
        
        return result;
    }
};
