class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int i=1;
        int curr=A[0];
        int dup=0;
        while(i<n){
            if(curr==A[i]){
                dup++;
            }else{
                if(dup>0){
                    A[i-dup]=A[i];
                }
                curr=A[i];
            }
            i++;
        }
        n-=dup;
        return n;
    }
};