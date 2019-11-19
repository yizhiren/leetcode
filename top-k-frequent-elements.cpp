auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
    return a.second > b.second;
};

class Solution {
public:
    
    map<int,int> count;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(auto i:nums){
            count[i]++;
        }
        priority_queue< pair<int,int>, vector< pair<int,int> >, decltype(cmp)> que(cmp);
        for(auto &pair:count){
            if(que.size() < k){
                que.push(pair);
            }else if(que.top().second<pair.second){
                que.pop();
                que.push(pair);
            }
        }
        
        list<int> ret;
        while(!que.empty()){
            auto &tmp =que.top();
            ret.push_front(tmp.first);
            que.pop();
        }
        
        return vector<int>(ret.begin(),ret.end());
    }
};
