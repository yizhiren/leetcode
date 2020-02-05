class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachIndex = 0;
        for(int i=0;i<nums.size();i++){
            if(i > maxReachIndex){
                return false;
            }
            maxReachIndex = max(maxReachIndex,i+nums[i]);
        }
        
        return true;
    }
};
