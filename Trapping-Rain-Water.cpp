class Solution {

public:
    int trap(int A[], int n) {
        if(n<=1)return 0;

        int result=0;
        int block=0;
        int leftHight=A[0];
        int leftPlace=0;

        int i=1;
        while(i<n){
            if(A[i]<leftHight){
                block+=leftHight-A[i];
            }else{
                leftHight = A[i];
                result+=block;
                block=0;
                leftPlace=i;
            }
            i++;
        }

        block=0;
        int rightHight=A[n-1];
        int rightPlace=n-1;
        i=n-2;
        while(i>=leftPlace){
            if(A[i]<rightHight){
                block+=rightHight-A[i];
            }else{
                rightHight = A[i];
                result+=block;
                block=0;
                rightPlace=i;
            }
            i--;

        }

        return result;
    }
};
