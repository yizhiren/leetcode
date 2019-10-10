class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums, int size) {
        if(size<0){
            return vector<vector<int>>({vector<int>()});
        }

        auto sub = subsets(nums,size-1);
        auto thisway = sub;
        for(auto &vec: sub){
            vec.push_back(nums[size]);
            thisway.push_back(vec);
        }
        return thisway;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets(nums,nums.size()-1);
    }
};
