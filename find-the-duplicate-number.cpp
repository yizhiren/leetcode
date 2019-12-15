

class Solution {
public:
    static bitset<INT_MAX> bits;
    int findDuplicate(vector<int>& nums) {
        bits.reset();
        for(auto num:nums){
            if (bits.test(num-1)) {
                return num;
            }
            bits.set(num-1);
        }
        
        return -1;
    }
};

bitset<INT_MAX> Solution::bits;

////
class Solution {
public:
    unordered_map<int,int> uniq;
    int findDuplicate(vector<int>& nums) {
       
        for(auto num:nums){
            if(uniq[num] != 0){
                return num;
            }
            uniq[num]++;

        }
        
        return -1;
    }
};

////
// https://leetcode.com/problems/find-the-duplicate-number/solution/ 
// solution 3 快慢指针判断环的位置
class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast=0;
        do{
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow==fast){
                break;
            }
        }while(1);
        int slow2=0;
        while(slow2!=slow){
            slow=nums[slow];
            slow2=nums[slow2];
        }
        return slow;
        
    }
};

