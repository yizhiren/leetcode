class Solution {
	bool checkLine(vector<vector<char> > &board){
		const int Num=9;
		map<int,int> nummap;
		for(int i=0;i<Num;i++){
			nummap.clear();
			for(int j=0;j<Num;j++){
				char ch=board[i][j];
				if('.'==ch)continue;
				int val=ch-'0';
				if(nummap.find(val)!=nummap.end()){
					return false;
				}
				nummap[val]=val;
			}
			
		}
		return true;
		
	}
	bool checkColumn(vector<vector<char> > &board){
		const int Num=9;
		map<int,int> nummap;
		for(int j=0;j<Num;j++){
			nummap.clear();
			for(int i=0;i<Num;i++){
				char ch=board[i][j];
				if('.'==ch)continue;
				int val=ch-'0';
				if(nummap.find(val)!=nummap.end()){
					return false;
				}
				nummap[val]=val;
			}
		}
		return true;
		
	}
	bool checkGrid(vector<vector<char> > &board){
		const int Num=9;
		map<int,int> nummap;
		for(int x=0;x<Num;x+=3){
			for(int y=0;y<Num;y+=3){
				nummap.clear();
				for(int xi=0;xi<3;xi++){
					for(int yi=0;yi<3;yi++){
						char ch=board[x+xi][y+yi];
						if('.'==ch)continue;
						int val=ch-'0';
						if(nummap.find(val)!=nummap.end()){
							return false;
						}
						nummap[val]=val;
					}
				}
			}
		}
		return true;
	}
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return checkLine(board) 
        	&& checkColumn(board)
        	&& checkGrid(board);
    }
};