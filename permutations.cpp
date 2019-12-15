class Solution {
public:
    vector<int> getOne(vector<int>& pre, int index, int v){
        vector<int> one;
        for(int i=0;i<pre.size();i++){
            if(i==index){
                one.push_back(v);
            }
            one.push_back(pre[i]);
        }
        return one;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()){
            return  vector<vector<int>>();
        }
        vector<vector<int>> prelevel;
        prelevel.push_back(vector<int>{nums[0]});
        
        for(int i=1;i<nums.size();i++){
            vector<vector<int>> thislevel;
            for(auto &arr:prelevel){
                for(int j=0;j<arr.size();j++){
                    thislevel.push_back(getOne(arr,j,nums[i]));
                }
                arr.push_back(nums[i]);
                thislevel.push_back(arr);
            }
            swap(thislevel,prelevel);
        }
        
        return prelevel;
    }
};
