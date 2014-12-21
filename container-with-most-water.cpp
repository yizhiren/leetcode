class Solution {
public:
    int maxArea(vector<int> &height) {
        int len=height.size();
        int maxwater=0;

        int low=0;int high=len-1;
        while(low < high){
        	int water=(high-low)*min(height[high],height[low]);
        	if(water>maxwater){
	        	maxwater=water;
	        }
	        if(height[low]<=height[high]){
        		low++;
        	}else{
	        	high--;
	        }
        }
        return maxwater;
    }
};