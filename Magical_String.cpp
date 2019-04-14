
const int MAX_LEN=100001;
int sequence[MAX_LEN];
class Solution {
public:
    int magicalString(int n) {
        if(n <= 0){
            return 0;
        }
        if(n<=2){
            return 1;
        }
        sequence[0] = 1;
        sequence[1] = 2;
        int pickIndex = 1;
        int setIndex = 1;
        int setValue = 2;
        
        while(setIndex < n){
            int cnt = sequence[pickIndex++];
            for(int i=0;i<cnt;i++){
                sequence[setIndex++]= setValue;
            }
            setValue = 3-setValue;
        }
        
        {
            int count = 0;
            for(int i=0;i<n;i++){
                if(sequence[i]==1){
                    count++;
                }
            }
            
            return count;
        }
        
    }
};
