class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> cache;
            
        vector<int> res;
        
        for(auto &n:nums1){
            cache[n]++;
        }
        for(auto &n:nums2){
            if(cache[n]>0){
                res.push_back(n);
                cache[n]--;
            }
        }
        
        return res;
    }
};
