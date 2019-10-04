class Solution {
public:
    vector<int> orig;
    default_random_engine random;
    Solution(vector<int>& nums) 
        :random(time(NULL))
    {
        orig = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    int rand(int low, int high) {
        uniform_int_distribution<int> dist(low,high);
        return dist(random);
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> copynums = orig;
        int len = orig.size();
        for(int i=0;i<len;i++){
            int changePlace = rand(i,len-1);
            swap(copynums[i],copynums[changePlace]);
        }
        return copynums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
