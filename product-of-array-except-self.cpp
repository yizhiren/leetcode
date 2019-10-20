class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        vector<int> res;
        
        
        int len = nums.size();
        if(len <= 1)return vector<int>();
        
        left.resize(len);
        right.resize(len);
        res.resize(len);
        
        int p=1;
        for(int i=0;i<len-1;i++){
            p *= nums[i];
            left[i]=p;
        }
        
        p=1;
        for(int i=len-1;i>=1;i--){
            p *= nums[i];
            right[i]=p;
        }
        
        res[0] = right[1];
        res[len-1] = left[len-2];
        for(int i=1;i<len-1;i++){
            res[i] = left[i-1] * right[i+1];
        }
        return res;
    }
};
