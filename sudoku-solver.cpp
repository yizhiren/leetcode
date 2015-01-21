class Solution {
	vector<vector<char> > *pboard;
	
	bool checkValid(int x,int y){
		map<int,int> nummap;
		const int Num=9;
		nummap.clear();
		for(int yi=0;yi<Num;yi++){
         	char ch=(*pboard)[x][yi];

			if('.'==ch)continue;
			int val=ch-'0';
			if(nummap.find(val)!=nummap.end()){
				return false;
			}
			nummap[val]=val;
         }
		
		nummap.clear();
 		for(int xi=0;xi<Num;xi++){
         	char ch=(*pboard)[xi][y];
			if('.'==ch)continue;
			int val=ch-'0';
			if(nummap.find(val)!=nummap.end()){
				return false;
			}
			nummap[val]=val;
         }
         
         nummap.clear();
         int baseX=x/3 * 3;int baseY=y/3 *3;
		 for(int xi=0;xi<3;xi++){
			for(int yi=0;yi<3;yi++){
				char ch=(*pboard)[baseX+xi][baseY+yi];
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

	bool tryValue(int x,int y,char v){
		//cout<<x<<","<<y<<","<<v <<endl;
		(*pboard)[x][y]=v;
		if(checkValid(x,y)==false)return false;
		
		int Num=9;
		int xi=x;int yi=y+1;
 		for(;xi<Num;xi++){ 			
         	for(;yi<Num;yi++){
         		if((*pboard)[xi][yi]!='.'){
		         	continue;
		         }
		         for(int v=1;v<=9;v++){
	         		if(tryValue(xi,yi,v+'0')){
		         		return true;
		         	}
	         	}
	         	(*pboard)[xi][yi] = '.';
	         	return false;
         	}
         	yi=0;
 		}
 		return true;
		
	}
public:
    void solveSudoku(vector<vector<char> > &board) {
         pboard = &board;
         int Num=9;
         for(int x=0;x<Num;x++){
         	for(int y=0;y<Num;y++){
	         	char ch=board[x][y];
	         	if(ch!='.'){
	         		continue;
	         	}
	         	for(int v=1;v<=9;v++){
	         		if(tryValue(x,y,v+'0')){
		         		return;
		         	}
	         	}
	         }
         }
         
    }
};