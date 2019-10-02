

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
