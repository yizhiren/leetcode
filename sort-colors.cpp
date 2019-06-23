class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int cnt = nums.size();
        
        int st = 0;
        int ed = cnt-1;
        for(int iter=0;iter < cnt;iter++){
            //cout << nums << "(" << iter << "," << st << "," << ed << ")" << endl;
            do{
                if(iter > ed) break;
                if(iter < st) break;
                
                if(nums[iter]==1)break;
                
                if(nums[iter]==2){
                    swap(nums[iter],nums[ed--]);
                }
                if(nums[iter]==0){
                    swap(nums[iter],nums[st++]);
                }
            }while(1);

        }
        return;
    }
};
