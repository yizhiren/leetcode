class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if(len<=1){
            return 0;
        }
       
        bool isDesc = false;
        int minValue = INT_MAX;
        for(int i=0;i<len-1;i++){
            if(nums[i]>nums[i+1]){
                isDesc = true;
            }
            if(isDesc) {
                minValue = min(minValue,nums[i+1]);
            }
        }
        if(!isDesc){
            return 0;
        }
        
        int p0=-1;
        for(int i=0;i<len;i++){
            if(nums[i]>minValue){
                p0 = i;
                break;
            }
        }
        
        ////////////////
        int maxValue = INT_MIN;
        isDesc = false;
        for(int i=len-1;i>0;i--){
            if(nums[i-1]>nums[i]){
                isDesc = true;
            }
            if(isDesc) {
                maxValue = max(maxValue,nums[i-1]);
            }
        }
        
        int p1=-1;
        for(int i=len-1;i>=0;i--){
            if(maxValue > nums[i]){
                p1 = i;
                break;
            }
        }
        
        return p1-p0+1;
        
    }
};



/////////////

class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if(len<=1){
            return 0;
        }
       
        stack<int> sk;
        int minStart = INT_MAX;
        for(int i=0;i<len;i++){
            if(sk.empty() || sk.top()<=nums[i]){
                sk.push(nums[i]);
            } else {
                while(!sk.empty() && sk.top()>nums[i]){
                    sk.pop();
                }
                minStart = min(minStart,int(sk.size()));
                sk.push(nums[i]);
            }
        }
        if(minStart == INT_MAX){
            return 0;
        }
        
        stack<int>().swap(sk);
        int maxEnd = INT_MIN;
        for(int i=len-1;i>=0;i--){
            if(sk.empty() || sk.top() >= nums[i]){
                sk.push(nums[i]);
            }else{
                while(!sk.empty() && sk.top()<nums[i]){
                    sk.pop();
                }
                maxEnd = max(maxEnd, int(len-sk.size()));
                sk.push(nums[i]);
            }
        }
        
        return maxEnd-minStart;
        
    }
};
