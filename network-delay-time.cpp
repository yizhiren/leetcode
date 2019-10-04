/*
Dijkstra算法一般步骤
1. 记录关系
2. 初始化访问过的组和最短距离
3. 访问第一个起始点，特殊处理
4. 访问后面最近的每一个点并更新最近的距离
  4.1 找出剩下的节点中最近的点
  4.2 划到访问过的组
  4.3 更新新的距离
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // 1. 记录关系
        vector<vector<int>> relation;
        for(int i=0;i<N+1;i++){
            relation.emplace_back(N+1,-1);
        }
        for(auto &time:times){
            relation[time[0]][time[1]] = time[2];
        }

        // 2. 初始化访问过的组和最短距离
        vector<int> dist = vector<int>(N+1,-1);
        vector<bool> visited = vector<bool>(N+1,false);
        
        // 3. 访问第一个起始点，特殊处理
        visited[K] = true;
        for(int i=1;i<=N;i++){
            dist[i] = relation[K][i];
        }
        dist[K] = 0;
        
        // 4. 访问后面最近的每一个点并更新最近的距离
        for(int x=2;x<=N;x++){
            int minnode = -1;
            int mindist = INT_MAX;
            // 找出剩下的节点中最近的点
            for(int i=1;i<=N;i++){
                if(visited[i]){
                    continue;
                }
                if (dist[i] >= 0 && dist[i] < mindist){
                    mindist = dist[i];
                    minnode = i;
                }
            }
            // 找不到通的了
            if(minnode < 0){
                return -1;
            }
            // 划到访问过的组
            visited[minnode] = true;
            // 更新新的距离
            for(int i=1;i<=N;i++){
                if(visited[i]){
                    continue;
                }
                
                if(relation[minnode][i]>=0 && (dist[i] < 0 ||dist[i]>dist[minnode]+relation[minnode][i])){
                    dist[i] = dist[minnode]+relation[minnode][i];
                }
            }
        }
        
        int maxdist = -1;;
        for(int i=1;i<=N;i++){
            if(dist[i] < 0){
                return -1;
            }
            maxdist = max(maxdist,dist[i]);
        }
        
        return maxdist;
    }
};
