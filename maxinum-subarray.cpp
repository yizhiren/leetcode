class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        int mx=INT_MIN;
        int cr=0;
        for(int i=0;i<len;i++){
            cr+=nums[i];
            if(cr>mx){
                mx=cr;
            }
            if(cr<0){
                // this part date will not used in the next sequence!
                // http://www.cnblogs.com/CCBB/archive/2009/04/25/1443455.html
                cr=0;
            }else{
                continue;
            }
        }
        return mx;
    }
};
