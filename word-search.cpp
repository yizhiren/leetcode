typedef pair<int,int> Point;

// dfs

class Solution {
public:
    map<Point, bool> visited;
    bool dfs(vector<vector<char>>& board, Point point, string& word,int wordindex) {
        if(visited[point]){
            return false;
        }
        if(wordindex == word.size()-1){
            return true;
        } 
        
        visited[point]=true;
        
        int i=point.first;
        int j=point.second;
        if(i-1>=0 && board[i-1][j]==word[wordindex+1]){
            if(dfs(board,Point(i-1,j),word,wordindex+1)){
                return true;
            }
        }
        if(i+1<board.size() && board[i+1][j]==word[wordindex+1]){
            if(dfs(board,Point(i+1,j),word,wordindex+1)){
                return true;
            }
        }
        if(j-1>=0 && board[i][j-1]==word[wordindex+1]){
            if(dfs(board,Point(i,j-1),word,wordindex+1)){
                return true;
            }
        }
        if(j+1<board[0].size() && board[i][j+1]==word[wordindex+1]){
            if(dfs(board,Point(i,j+1),word,wordindex+1)){
                return true;
            }
        }
        visited[point]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if(!row)return false;
        int col = board[0].size();
        if(!col)return false;
        if(word.empty())return false;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,Point(i,j),word,0)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
