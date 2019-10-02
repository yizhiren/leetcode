class Solution {
public:
    
    int findNextZero(vector<int>& nums, int pos) {
        int len = nums.size();
        for(int i=pos;i<len;i++){
            if (nums[i]==0){
                return i;
            }
        }
        return -1;
    }
     int fincNextNonZero(vector<int>& nums, int pos) {
        int len = nums.size();
        for(int i=pos;i<len;i++){
            if (nums[i]!=0){
                return i;
            }
        }
        return -1;
    }  
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()){
            return;
        }
        int p0=-1;
        int p1=-1;
        while(1) {
            p0 = findNextZero(nums,++p0);
            if(p0 <0){
                break;
            }
            p1 = fincNextNonZero(nums,p0);
            if (p1<0){
                break;
            }
            swap(nums[p0],nums[p1]);
        }

        
        
    }
};
