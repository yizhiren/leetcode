class Solution {
public:
    vector<int> increaseNumEndAt;
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()){
            return false;
        }
        int maxIncreaseNum = 1;
        int len = nums.size();
        increaseNumEndAt = vector<int>(len,1);
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && increaseNumEndAt[j]+1>increaseNumEndAt[i]){
                    increaseNumEndAt[i] = increaseNumEndAt[j]+1;
                    if(increaseNumEndAt[i] > maxIncreaseNum){
                        maxIncreaseNum = increaseNumEndAt[i];
                        if(maxIncreaseNum >= 3){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};

///////////////////

class Solution {
public:
    vector<int> increaseNumEndAt;
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()){
            return false;
        }
        int n_min = INT_MAX;
        int n_secondmin = INT_MAX;
        int len = nums.size();
        for(int i=0;i<len;i++){
            int n = nums[i];
            if(n>n_secondmin){
                return true;
            }
            if(n>n_min){
                n_secondmin = min(n_secondmin,n);
            } else {
                n_min = n;
            }
        }
        
        return false;
    }
};
