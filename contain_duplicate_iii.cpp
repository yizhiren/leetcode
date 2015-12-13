/**

 * make the find step into map to reduce O(n*n)->O(n*lg(n))

 * 

 */

 



class Solution {

public:

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        map<int,int> cache;

        if(nums.size()<2)return false;

        if(k==0)return false;

        

        

        cache[nums[0]] = 1;

        for(int i=1;i<nums.size();i++){

            auto place = cache.lower_bound(nums[i]-t); 

            if(place != cache.end() && abs((place->first)-nums[i])<=t){

                return true;

            }

            cache[nums[i]] = 1;

            if(i>=k){

                cache.erase(cache.find(nums[i-k]));

            }

        }

        return false;

        

    }

};
