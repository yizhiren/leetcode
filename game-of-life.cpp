class Solution {
public:
    int getActiveNeighbor(const vector<vector<int>>& board, int i,int j){
        int count=0;
        if(i-1>=0){
            if(j-1>=0 && board[i-1][j-1]){
                count++;
            }
            if(board[i-1][j]){
                count++;
            }
            if(j+1<board[0].size() && board[i-1][j+1]){
                count++;
            }
        }
        {
            if(j-1>=0 && board[i][j-1]){
                count++;
            }
            if(j+1<board[0].size() && board[i][j+1]){
                count++;
            }
        }
        if(i+1<board.size()){
            if(j-1>=0 && board[i+1][j-1]){
                count++;
            }
            if(board[i+1][j]){
                count++;
            }
            if(j+1<board[0].size() && board[i+1][j+1]){
                count++;
            }
        }
        
        return count;
    }
    
    int nextState(const vector<vector<int>>& board, int i,int j){
        int count1 = getActiveNeighbor(board,i,j);

        if(board[i][j]){
            if (count1 <= 1){
                return 0;
            }
            if (count1 > 3) {
                return 0;
            }
            return 1;
        }
        if (count1==3){
            return 1;
        }
        
        return 0;
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector< tuple<int,int,int> > actions;
        
        int m = board.size();
        if(m<=0)return;
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int newState = nextState(board,i,j);
                if(newState != board[i][j]){
                    actions.emplace_back(newState,i,j);
                }
            }
        }
        
        for(auto& action:actions){
            board[get<1>(action)][get<2>(action)] = get<0>(action);
        }
        
        
    }
};

//////////////////

class Solution {
public:
    int getActiveNeighbor(const vector<vector<int>>& board, int i,int j){
        int count=0;
        if(i-1>=0){
            if(j-1>=0 && abs(board[i-1][j-1])==1){
                count++;
            }
            if(abs(board[i-1][j])==1){
                count++;
            }
            if(j+1<board[0].size() && abs(board[i-1][j+1])==1){
                count++;
            }
        }
        {
            if(j-1>=0 && abs(board[i][j-1])==1){
                count++;
            }
            if(j+1<board[0].size() && abs(board[i][j+1])==1){
                count++;
            }
        }
        if(i+1<board.size()){
            if(j-1>=0 && abs(board[i+1][j-1])==1){
                count++;
            }
            if(board[i+1][j]){
                count++;
            }
            if(j+1<board[0].size() && abs(board[i+1][j+1])==1){
                count++;
            }
        }
        
        return count;
    }
    
    int nextState(const vector<vector<int>>& board, int i,int j){
        int count1 = getActiveNeighbor(board,i,j);

        if(board[i][j]){
            if (count1 <= 1){
                return 0;
            }
            if (count1 > 3) {
                return 0;
            }
            return 1;
        }
        if (count1==3){
            return 1;
        }
        
        return 0;
        
    }
    
    // 第一轮遍历1变0记为-1，0变1记为2，这样就在一个格子中即有原始值信息，又有新的值信息；第二轮遍历把-1变成0，把2变成1
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        if(m<=0)return;
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int newState = nextState(board,i,j);
                if(board[i][j]==0 && newState==1){
                    board[i][j]=2;
                }
                if(board[i][j]==1 && newState==0){
                    board[i][j]=-1;
                }
                
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(board[i][j]==2){
                    board[i][j] = 1;
                }
                if(board[i][j]==-1){
                    board[i][j]=0;
                }
                
            }
        }
        
    }
};
