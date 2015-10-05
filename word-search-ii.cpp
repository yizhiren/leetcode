


class Solution {

    struct ND{
        ND(ND* fath=NULL, char chr = '*'){
            for(int i=0;i<26;i++){
                subnds.push_back(NULL);
            }
            ch=chr;
            father = fath;
            endingPoint = false;

        }
        ~ND(){
             for(int i=0;i<26;i++){
                delete(subnds[i]);
            }           
        }
        char ch;
        vector<ND*> subnds;
        ND* father;
        bool endingPoint;
    };
    typedef vector<ND*> ND_VEC;
    typedef pair<int,int> POS;
    typedef map<POS,bool> POSMAP;
    set<string> setres;
public:
    ND rt;
    void makeTrie(vector<string>& words){
        ND* curr = &rt;
        for(int i=0;i<words.size();i++){
            string &str = words[i];
            curr = &rt;
            for(int j=0;j<str.length();j++){
                char ch=str[j];
                int index=ch-'a';
                if(!curr->subnds[index]){
                    curr->subnds[index] = new ND(curr, ch);
                }
                curr = curr->subnds[index];
            }
            curr->endingPoint=true;
        }
    }

    bool isPosAlready(POSMAP &posmap,POS &pos){
        if(posmap.find(pos) == posmap.end() ){
            return false;
        }
        return posmap[pos];
    }

    void reportOne(ND* tail){
        string tmp;
        while(tail->ch != '*'){
            tmp += tail->ch;
            tail = tail->father;
        }
        reverse(tmp.begin(), tmp.end());
        //printf("%s\n",tmp.c_str() );
        setres.insert(tmp);
    }

    void chcek(const vector<vector<char>>& board, const POS &pos,  ND* curr, POSMAP &posmap){
        int lns = board.size();
        int cols = board[0].size();

        if(board[pos.first][pos.second] != curr->ch){
            return ;
        }
        if(curr->endingPoint){
            reportOne(curr);
        }
        posmap[pos] = true;
        int ln=pos.first;
        int col=pos.second;

        vector<POS> vecpos;
        POS shang(ln-1,col);
        if( ln-1>=0 && !isPosAlready(posmap,shang)){
            vecpos.push_back(shang);
        }
        POS xia(ln+1,col);
        if( ln+1<lns && !isPosAlready(posmap,xia) ){
            vecpos.push_back(xia);
        }
       POS zuo(ln,col-1);
        if( col-1>=0 && !isPosAlready(posmap,zuo) ){
            vecpos.push_back(zuo);
        }
       POS you(ln,col+1);
        if( col+1<cols && !isPosAlready(posmap,you) ){
            vecpos.push_back(you);
        }

        for(int i=0;i<vecpos.size();i++){
            for(int j=0;j<26;j++){
                if(curr->subnds[j]){
                    chcek(board, vecpos[i],  curr->subnds[j], posmap);
                }
            }
        }


        posmap[pos] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int lns = board.size();
        if(lns==0 || words.size()==0){
            return vector<string>();
        }
        int cols = board[0].size();
        makeTrie(words);
        for(int i=0;i<lns;i++){
            for(int j=0;j<cols;j++){
                POSMAP posmap;
                int index=board[i][j]-'a';
                if(rt.subnds[index]){
                    chcek(board,POS(i,j), rt.subnds[index],posmap);
                }
            }
        }
        return vector<string>(setres.begin(),setres.end());
    }
};