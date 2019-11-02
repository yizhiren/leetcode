class Solution {
    int findeEchangePlace(vector<int> &num,int i){
        int len=num.size();
        int det=9999;
        int place=i;
        for(int j=i+1;j<len;j++){
            if(num[j]<=num[i]){
                continue;
            }
            if(num[j]-num[i]<det){
                det=num[j]-num[i];
                place=j;
            }
        }
        return place;
    }
public:
    void nextPermutation(vector<int> &num) {
        int len=num.size();
        if(len<=1)return;
        int changeplace=-1;
        for(int i=len-1;i>0;i--){
            if(num[i]>num[i-1]){
                changeplace=i-1;
                break;
            }
        }
        if(changeplace==-1){
            sort(num.begin(),num.end());
            return;
        }
        int exchangeplace=findeEchangePlace(num,changeplace);
        int tmp=num[changeplace];
        num[changeplace]=num[exchangeplace];
        num[exchangeplace]=tmp;
        sort(&num[changeplace+1],&num[0]+len);
        
    }
};


////////////////////
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()){
            return;
        }
        
        int idx = nums.size()-1;
        while(idx > 0){
            if(nums[idx]<=nums[idx-1]){
                idx--;
            }else{
                break;
            }
        }
        
        if(idx==0){
            sort(nums.begin(),nums.end());
        }else{
            int i=nums.size()-1;
            for(;i>=idx;i--){
                if(nums[i]>nums[idx-1]){
                    break;
                }
            }
            swap(nums[idx-1],nums[i]);
            auto iter = nums.begin();
            advance(iter,idx);
            sort(iter,nums.end());
        }
        
        return;
    }
};
