
class Solution {

public:
    int firstMissingPositive(int A[], int n) {
        int maxInputValue=0;
        for(int i=0;i<n;i++){
            if(A[i]>maxInputValue){
                maxInputValue = A[i];
            }
        }

        if(maxInputValue==0)return 1;
        int mallocSize = sizeof(int) * (maxInputValue/8+1);
        int *bitmap = (int*)malloc(mallocSize);
        memset(bitmap,0,mallocSize);

        for(int i=0;i<n;i++){
            if(A[i]<=0)continue;
            int index = A[i]/8;
            int offset = A[i]%8;
            bitmap[index] |= (1<<offset);
        }
        for(int i=1;i<=maxInputValue;i++){
            int index = i/8;
            int offset = i%8;

            if((bitmap[index] & (1<<offset)) == 0){
                delete bitmap;
                return i;
            }
        }
        delete bitmap;
        return maxInputValue+1;

    }
};