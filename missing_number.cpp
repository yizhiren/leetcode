class Solution {

public:

    int missingNumber(vector<int>& nums) {

        vector<int> tmap;

        tmap.resize(nums.size()+1);

        for(int i=0;i<tmap.size();i++){

            tmap[i] = 0;

        }



        for(int i=0;i<nums.size();i++){

            tmap[nums[i]] = 1;

        }

        for(int i=0;i<tmap.size();i++){

            if(tmap[i] == 0){

                return i;

            }

        }

        return nums.size();

    }

};
