class Solution {
public:
    int maxOfThree(int a, int b, int c) {
        return max(max(a,b),c);
    }
    int minOfThree(int a, int b, int c) {
        return min(min(a,b),c);
    }
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        int len = nums.size();

        int maxAll = nums[0];
        int minDy = nums[0];
        int maxDy = nums[0];
        for(int i=1;i<len;i++){
            int a = nums[i];
            int b = a*minDy;
            int c = a*maxDy;
            maxDy = maxOfThree(a,b,c);
            minDy = minOfThree(a,b,c);
            maxAll = max(maxAll,maxDy);
        }
        return maxAll;
        
    }
};
