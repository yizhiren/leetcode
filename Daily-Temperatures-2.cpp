class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.empty())return vector<int>();
        int len = T.size();
        vector<int> result(len);
        result[len-1] = 0;
        
        auto findBiggerPlace = [&](int i){
            int ip = i+1;
            while(T[ip]<=T[i]){
                if(result[ip]==0){
                    break;
                }
                ip+=result[ip];
            }
            return ip;
        };
        
        for(int i=result.size()-2;i>=0;i--){
            int ip = findBiggerPlace(i);

            if(T[ip]>T[i]){
                result[i]=ip-i;
            }else{
                result[i]=0;
            }
            
        }
        
        return result;
    }
};
