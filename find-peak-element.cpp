class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())return -1;
        return findPeakElement(nums, 0, nums.size()-1);
    }
    int findPeakElement(vector<int>& nums, int low, int high) {
        if(low>=high){
            return low;
        }
        int mid = (low+high)/2;
        if(nums[mid]<nums[mid+1]){
            return findPeakElement(nums,mid+1, high);
        }else{
            return findPeakElement(nums,low, mid);
        }
    }
};
