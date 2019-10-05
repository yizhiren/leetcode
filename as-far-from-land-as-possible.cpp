// BFS，从land的位置开始入队列是关键，这样碰到个water也就是这个water到land的dist
// 如果任意water开始入队列，无论碰到lang和碰到water都不能说明什么意义


typedef tuple<int,int,int> TUPLE;

class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        int len = grid.size();
        
        queue<TUPLE> que;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(grid[i][j]){
                    que.push(TUPLE(i-1,j,1));
                    que.push(TUPLE(i+1,j,1));
                    que.push(TUPLE(i,j-1,1));
                    que.push(TUPLE(i,j+1,1));
                }
            }
        }
        
        int maxDist = -1;
        while(!que.empty()){
            TUPLE tp = que.front();
            que.pop();
            int x = get<0>(tp);
            int y = get<1>(tp);
            int deep = get<2>(tp);
            
            if(x>=0 && x<len && y>=0 && y<len && !grid[x][y]) {
                maxDist = max(maxDist, deep);
                grid[x][y] = deep;//置为非0即可。
                que.push(TUPLE(x-1,y,deep+1));
                que.push(TUPLE(x+1,y,deep+1));
                que.push(TUPLE(x,y-1,deep+1));
                que.push(TUPLE(x,y+1,deep+1));           
            }
        }

        return maxDist;
        
    }
};
