class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long seq=INT_MIN;
        long maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            seq = max(long(nums[i]),seq+nums[i]);
            maxsum = max(maxsum,seq);
        }
        
        return maxsum;
    }
};
