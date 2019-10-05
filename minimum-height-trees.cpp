

// DFS with cache
class Solution {
public:
    // 记录图关系
    vector<vector<int>> relation;
    
    // 这是防止算法超时的关键，利用cache拦截重复计算
    // 缓存<某个节点,某个方向上>的深度
    map<pair<int,int>, int> cache;
    // 记录是否正在访问
    map<int,bool> visiting;
    
    // 遍历所有节点，使缓存充满数据
    int walk(int i){
        int maxSubDeep = 0;
        visiting[i]=true;
        for(auto &link:relation[i]){
            if(!visiting[link]){
                int subDeep=0;
                if(cache.find(pair<int,int>(i,link)) != cache.end()){
                    subDeep = cache[pair<int,int>(i,link)];
                }else{
                    subDeep = walk(link) + 1;
                    cache[pair<int,int>(i,link)] = subDeep;
                }
                maxSubDeep = max(maxSubDeep,subDeep);
            }
        }
        visiting[i]=false;
        return maxSubDeep;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0){
            return vector<int>();
        }
        if(n==1){
            return vector<int>(1,0);
        }
        
        // 构造初始图
        for(int i=0;i<n;i++){
            relation.emplace_back();
        }
        // 构造初始图
        for(auto &edge:edges){
            relation[edge[0]].push_back(edge[1]);
            relation[edge[1]].push_back(edge[0]);
        }
        
        // 构造初始遍历数，这里选择叶子节点
        vector<int> beginer;
        for(int i=0;i<n;i++){
            if(relation[i].size()==1){
                beginer.push_back(i);
            }
        }
        
        // 遍历树
        for(auto begin:beginer){
            walk(begin);
        }

        // 记录每个树的深度和最浅树的深度
        vector<int> maxDeeps = vector<int>(n,-1);
        int minDeep = INT_MAX;
        
        // 找出最浅深度
        for(int i=0;i<n;i++){
            for(auto link:relation[i]){
                maxDeeps[i] = max(maxDeeps[i],cache[pair<int,int>(i,link)]);
            }
            minDeep = min(minDeep,maxDeeps[i]);
        }

        // 找出同深度的根节点
        vector<int> result;
        for(int i=0;i<n;i++){
            if(maxDeeps[i]==minDeep){
                result.push_back(i);
            }
        }
        return result;
    }
};

///////////////////////////////////////////////////////

// floyd算法超时了，floyd总是要计算所有点的距离，总是o(n3)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> relation;
        for(int i=0;i<n;i++){
            relation.emplace_back(n,-1);
        }
        
        
        for(auto &edge:edges){
            relation[edge[0]][edge[1]] = 1;
            relation[edge[1]][edge[0]] = 1;
        }
        
        // floyd计算两两最短距离
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i != j && relation[i][k]>0 && relation[k][j]>0 && 
                       (relation[i][j]<0||relation[i][k]+relation[k][j]<relation[i][j])){
                        relation[i][j] = relation[i][k]+relation[k][j];
                    }
                }
            }
        }
        //找出最小高度
        int minHeight = INT_MAX;
        {
            for(int i=0;i<n;i++){
                int maxDeep = 0;
                for(int j=0;j<n;j++){
                    
                    cout << "maxdeep "<<i << "=" <<maxDeep<<endl;
                    maxDeep = max(maxDeep,relation[i][j]);
                }
                minHeight = min(minHeight,maxDeep);
            }
        }
         cout << "minHeight " << "=" <<minHeight<<endl;
        
        vector<int> result;
        {
            for(int i=0;i<n;i++){
                int maxDeep = 0;
                for(int j=0;j<n;j++){
                    maxDeep = max(maxDeep,relation[i][j]);
                }
                if(maxDeep==minHeight){
                    result.push_back(i);
                }
            }
        }  
        
        return result;
    }
};
