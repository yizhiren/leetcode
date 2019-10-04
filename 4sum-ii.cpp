class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int > mapAB;
        unordered_map<int,int > mapCD;
        
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                mapAB[A[i]+B[j]]++;
            }
        }
        
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++){
                mapCD[C[i]+D[j]]++;
            }
        }
        
        int res = 0;
        for(const auto& pr: mapAB){
            int sum = pr.first;
            const auto& listAB = pr.second;
            int leftSum = -sum;
            const auto& listCD = mapCD[leftSum];
            res += listAB * listCD;
        }
        
        return res;
    }
};
