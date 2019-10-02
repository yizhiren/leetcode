

class Solution {
public:
    /** initialize your data structure here. */
    
    map<int,int> stream;
    int count;
    
    Solution() {
        stream.clear();
        count = 0;
    }
    
    void addNum(int num) {
        stream[num] ++;
        count ++;
    }
    
    void deleteNum(int num) {
        stream[num] --;
        if(stream[num]==0){
            auto iter = stream.find(num);
            stream.erase(iter);
        }
        count --;
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()){
            return vector<double>();
        }
        
        vector<double> res;
        int len = nums.size();
        for (int i=0;i<k;i++){
            addNum(nums[i]);
        }
        res.push_back(findMedian());
        
        
        for(int i=k;i<len;i++){
            addNum(nums[i]);
            deleteNum(nums[i-k]);
            res.push_back(findMedian());
        }
        
        return res;
    }
    
    double findMedian() {
        if (count==0)return 0;
        
        int nth = count/2 + count%2;
        double res = 0;
        
        
        int walkCount = 0;
        auto iter = stream.begin();
        while(iter != stream.end()){
            int k = iter->first;
            int v = iter->second;
            walkCount += v;
            if (walkCount >= nth) {
                res = k;
                if(count%2==0){
                    if (walkCount>nth){
                        // nothing   
                    } else {
                        res = (res+((++iter)->first))/2;
                    }
                }
                return res;
            }
            iter++;
        }
        
        return res;
    }
};
