class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())return 0;
        priority_queue<int,vector<int>,greater<int> > store;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                store.push(matrix[i][j]);
            }
        }
        int res;
        for(int i=0;i<k;i++){
            res = store.top();
            store.pop();
        }
        
        return res;
    }
};
