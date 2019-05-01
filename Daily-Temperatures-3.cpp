class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.empty())return vector<int>();
        int len = T.size();
        vector<int> result(len,0);
        
        stack<int> unmeeted;
        for(int i=0;i<len;i++){
            while(!unmeeted.empty() && T[unmeeted.top()]<T[i]){
                int tmp = unmeeted.top();
                result[tmp]=i-tmp;
                unmeeted.pop();
            }
            unmeeted.push(i);
        }
        
        
        return result;
    }
};
