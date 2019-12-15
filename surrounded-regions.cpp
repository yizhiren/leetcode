typedef pair<int,int> pr;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row <=0){
            return;
        }
        int col = board[0].size();
        if(col <=0){
            return;
        }
        
        queue<pr> que;
        for(int i=0;i<col;i++){
            if(board[0][i]=='O'){
                que.push(pr(0,i));
            }
            if(board[row-1][i]=='O'){
                que.push(pr(row-1,i));
            }
        }
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'){
                que.push(pr(i,0));
            }
            if(board[i][col-1]=='O'){
                que.push(pr(i,col-1));
            }
        }
        
        while(!que.empty()){
            auto &v = que.front();
            int x= v.first;
            int y=v.second;
            board[x][y]='R';
            if(x-1>=0 && board[x-1][y]=='O'){
                que.push(pr(x-1,y));
            }
            if(x+1<row && board[x+1][y]=='O'){
                que.push(pr(x+1,y));
            }
            if(y-1>=0 && board[x][y-1]=='O'){
                que.push(pr(x,y-1));
            }
            if(y+1<col && board[x][y+1]=='O'){
                que.push(pr(x,y+1));
            }
            que.pop();
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='R'){
                    board[i][j]='O';
                }
            }
        }
        
    }
};
