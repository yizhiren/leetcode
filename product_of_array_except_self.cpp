class Solution {

public:

    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result;

        long long all = 1;

        int zeroNum=0;

        for(int i=0;i<nums.size();i++){

            if(nums[i]==0){

                zeroNum++;

                continue;

            }

            all *=nums[i];

        }

        for(int i=0;i<nums.size();i++){

            if(zeroNum>=2){

                result.push_back(0);

            }else if(zeroNum==1){

                result.push_back(nums[i]==0?all:0);

            }else{

                result.push_back(all/nums[i]);

            }

            

        }

        return result;

    }

};
