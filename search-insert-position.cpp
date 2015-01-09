class Solution {
    pair<bool,int> searchTarget(int A[], int low, int high, int target){
        int mid=(low+high)/2;
        if(A[mid]==target){
            return pair<bool,int>(true,mid);
        }
        if(low==high)return pair<bool,int>(false,mid);
        if(A[mid]>target){
            if(mid-1<low)return pair<bool,int>(false,low);
            else return searchTarget(A, low,mid-1 , target);
        }else{
            if(mid+1>high)return pair<bool,int>(false,high);
            else return searchTarget(A, mid+1 ,high, target);
        }
    }
public:
    int searchInsert(int A[], int n, int target) {
        pair<bool,int> ans=searchTarget(A, 0, n-1, target);
        if(ans.first){
            return ans.second;
        }else if(A[ans.second]>target){
            return ans.second;
        }else{
            return ans.second+1;
        }
    }
};