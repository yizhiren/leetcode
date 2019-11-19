class Solution {
public:
    
    unsigned long long multi(const map<int,bool>& data){
        unsigned long long ret = 1;
        for(const auto &pr: data) {
            if(pr.second){
                ret *= pr.first;
            }
        }
        
        return ret;
    }
    //uniquePaths =C(t,min(x,y))
    int uniquePaths(int m, int n) {
        
        int x = m-1;
        int y = n-1;
        
        int t = x+y;
        
        
        map<int,bool> up;
        for(int i=1;i<=t;i++){
            up[i]=true;
        }
        
        map<int,bool> down;
        {
            int bigger = max(x,y);
            int little = min(x,y);
            for(int i=1;i<=bigger;i++){
                up[i]=false;
            }
            for(int i=1;i<=little;i++){
                down[i]=true;
            }
        }
        
        return multi(up)/multi(down);
        
    }
};

/////////////////
// DP solution
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        vector<int> line(n,1);
        vector< vector<int> > table(m,line);
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                table[i][j] = table[i][j-1]+table[i-1][j];
            }
        }
        
        return table[m-1][n-1];

        
    }
};
