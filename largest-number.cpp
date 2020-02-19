bool cmp(int a, int b) {
    string str_a = to_string(a);
    string str_b = to_string(b);
    return str_a+str_b > str_b+str_a;
}


class Solution {
public:
    string merge(vector<int>& nums){
        string ret = "";
        for(int i=0;i<nums.size();i++){
            if(ret=="0"){
                break;
            }
            ret += to_string(nums[i]);
        }
        
        return ret;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        
        return merge(nums);
    }
};
