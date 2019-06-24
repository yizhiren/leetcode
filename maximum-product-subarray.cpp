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
        vector<int> mins(len);
        vector<int> maxs(len);
        int maxAll = nums[0];
        mins[0] = nums[0];
        maxs[0] = nums[0];
        for(int i=1;i<len;i++){
            int a = nums[i];
            int b = a*mins[i-1];
            int c = a*maxs[i-1];
            maxs[i] = maxOfThree(a,b,c);
            mins[i] = minOfThree(a,b,c);
            if(maxs[i] > maxAll){
                maxAll = maxs[i];
            }
        }
        return maxAll;
        
    }
};
