typedef pair<int,int> Point;

class Solution {

    public:
    vector<std::vector<bool> > statusTable;
    int numIslands(vector<vector<char> >& grid) {
        int m = grid.size();
        if(m<=0)return 0;

        int n=grid[0].size();
        if(n<=0)return 0;

        vector<bool> tmp(n,false);
        statusTable = vector< vector<bool> >(m,tmp);

        int island=0;
        queue<Point> que;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                que.push(Point(i,j));
            }
        }
        
        while(!que.empty()){
            auto &pr = que.front();
            if(workIsland(grid,pr.first,pr.second)){
                island++;
            }
            que.pop();
        }
        
        return island;
    }
    
    

    bool isValidPoint(std::vector<std::vector<char> >& grid,int i,int j){
        
        int m=grid.size();
        int n=grid[0].size();
        return (i>=0 && i<m)
            && (j>=0 && j<n)
            && (grid[i][j]!='0')
            && !statusTable[i][j];
    }

    bool workIsland(std::vector<std::vector<char> >& grid,int i,int j){
        if (statusTable[i][j]){
            return false;
        }
        
        std::queue<Point> landqueue;
        landqueue.push(Point(i,j));
        statusTable[i][j]=true;
        while(!landqueue.empty()){
            Point &tmp = landqueue.front();
            //std:cout<<tmp.first<<","<<tmp.second<<std::endl;
            if(isValidPoint(grid,tmp.first-1,tmp.second)){
                landqueue.push(Point(tmp.first-1,tmp.second));
                statusTable[tmp.first-1][tmp.second]=true;   
            }
            if(isValidPoint(grid,tmp.first+1,tmp.second)){
                landqueue.push(Point(tmp.first+1,tmp.second));
                statusTable[tmp.first+1][tmp.second]=true;
            }
            if(isValidPoint(grid,tmp.first,tmp.second-1)){
                landqueue.push(Point(tmp.first,tmp.second-1));
                statusTable[tmp.first][tmp.second-1]=true;
            }
            if(isValidPoint(grid,tmp.first,tmp.second+1)){
                landqueue.push(Point(tmp.first,tmp.second+1));
                statusTable[tmp.first][tmp.second+1]=true;
            }
            landqueue.pop();
        }
        return true;
        
    
    }
};
