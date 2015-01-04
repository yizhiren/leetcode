class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0)return 0;
        if(n==1)return A[0]==elem?0:1;
        int i=0;
        int moved=0;
        while(i<n){
            if(A[i]==elem){
                moved++;
            }else{
                if(moved>0){
                    A[i-moved]=A[i];
                }
            }
            i++;
        }
        return n-moved;
    }
};