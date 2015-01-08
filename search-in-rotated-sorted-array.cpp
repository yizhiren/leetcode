/*
	I was shocked , this is also accepted.
	i think ,it want me to use dichotomy to find out the pivot .
	but seems needn't.
	
*/
class Solution {
public:
    int search(int A[], int n, int target) {

        for(int i=0;i<n;i++){
            if(A[i]==target){
                return i;
            }
        }
        return -1;


    }
};