/*
	I was shocked , this is also accepted.
	i think ,it want me to use dichotomy to find out the pivot .
	but seems needn't.
	
*/
class Solution {
public:
    int search(int A[], int n, int target) {

        for(int i=0;i<n;i++){
            if(A[i]==target){
                return i;
            }
        }
        return -1;


    }
};

////////////////////
// 二分法
class Solution {
public:
    int search(vector<int>& nums, int target, int start, int end) {
        if (start > end){
            return -1;
        }
        
        if(start==end){
            return nums[start]==target?start:-1;
        }
        
        int mid = (start+end)/2;
        if (nums[mid]== target){
            return mid;
        }
        
        bool isLeftAsc = nums[mid] >= nums[start];
        if (isLeftAsc && target <= nums[mid] && target >= nums[start]){
            return search(nums, target, start, mid);
        } 
        if (!isLeftAsc && (target <= nums[mid] || target >= nums[start])){
            return search(nums, target, start, mid);
        }
        
        bool isRightAsc = nums[mid+1] <= nums[end];
        if (isRightAsc && target >= nums[mid+1] && target <= nums[end]){
            return search(nums, target, mid+1, end);
        } 
        if (!isRightAsc && (target >= nums[mid+1] || target <= nums[end])){
            return search(nums, target, mid+1, end);
        } 
        
        
        return -1;
        
    }
    
    int search(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);
    }
};
