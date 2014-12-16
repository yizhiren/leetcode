class Solution {
public:
    int reverse(int x) {

        int val=0;
        while(x){
            if(x>0){
                if(INT_MAX/10 < val || (INT_MAX/10 == val && INT_MAX%10 <x%10)){
        	        return 0;
	            } 
            }else{
                if(INT_MIN/10 > val || (INT_MIN/10 == val && INT_MIN%10 > x%10)){
                    return 0;
                }
            }

        	val=10*val+x%10;
        	x=x/10;
        }

        return val;
    }
};


