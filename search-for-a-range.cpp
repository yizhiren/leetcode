class Solution {
    int findLeft(int A[],int low, int high,int target){
        if(low>high){
            return -1;
        }
        int mid=(low+high)/2;
        if(A[mid]==target){
            if(mid-1<low || A[mid-1]<A[mid]){
                return mid;
            }else{
                return findLeft(A,low, mid-1,target);
            }
        }else{
            if(A[mid]>target){
                return findLeft(A,low, mid-1,target);
            }else{
                return findLeft(A,mid+1, high,target);
            }
        }
    }
    
    int findRight(int A[],int low, int high,int target){
        if(low>high){
            return -1;
        }
        int mid=(low+high)/2;
        if(A[mid]==target){
            if(mid+1>high || A[mid+1]>A[mid]){
                return mid;
            }else{
                return findRight(A,mid+1, high,target);
            }
        }else{
            if(A[mid]>target){
                return findRight(A,low, mid-1,target);
            }else{
                return findRight(A,mid+1, high,target);
            }
        }
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        int left=findLeft(A,0, n-1,target);
        if(-1==left){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int right=findRight(A,left, n-1,target);
        result.push_back(left);
        result.push_back(right);
        return result;
        
    }
};