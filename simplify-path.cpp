// clearPath部分链表的处理非常繁琐，用split之后处理可能更方便些

struct DIR{
    string name;
    DIR* sub;
    DIR* father;
    virtual ~DIR(){
        delete(sub);
    }
    DIR(string _name, DIR* _sub, DIR* _father)
        :name(_name)
        ,sub(_sub)
        ,father(_father)
    {}
};

class Solution {
public:
    DIR* getSubPath(string& path, int index){
        int len = path.length();
        if(index >= len){
            return NULL;
        }
        if(path[index]!='/'){
            return NULL;
        }
        
        int st = index;
        while(st < len && path[st]=='/')st++;
        if (st >= len){
            return NULL;
        }
        int ed = st;
        while(ed < len && path[ed]!='/')ed++;
        DIR* pdir = new DIR{path.substr(st,ed-st), NULL, NULL};
        DIR *psub = getSubPath(path,ed);
        if(psub){
            pdir->sub = psub;
            psub->father = pdir;
        }
        
        return pdir;
    }
    
    DIR* clearPath(DIR* pdir){
        DIR* root = pdir;
        while(pdir){
            if(pdir->name=="."){
                if(pdir->father==0){
                    DIR* tmp = pdir;
                    root = pdir->sub;
                    if(pdir->sub){
                        pdir->sub->father=0;
                    }
                    pdir = pdir->sub;
                    
                    tmp->sub=0;
                    delete(tmp);
                    
                }else{
                    DIR* tmp = pdir;
                    pdir->father->sub = pdir->sub;
                    if(pdir->sub){
                        pdir->sub->father = pdir->father;
                    }
                    pdir = pdir->sub;
                    
                    tmp->sub=0;
                    delete(tmp);
                }
            }else if(pdir->name==".."){
                if(pdir->father && pdir->father->father){
                    DIR* tmp1 = pdir->father;
                    DIR* tmp2 = pdir;
                    pdir->father->father->sub = pdir->sub;
                    if(pdir->sub){
                        pdir->sub->father = pdir->father->father;
                    }
                    pdir = pdir->sub;
                    
                    tmp1->sub=0;
                    tmp2->sub=0;
                    delete(tmp1);
                    delete(tmp2);
                    
                }else if(pdir->father && !pdir->father->father){
                    DIR* tmp1 = pdir->father;
                    DIR* tmp2 = pdir;
                    root = pdir->sub;
                    if(pdir->sub){
                        pdir->sub->father=0;
                    }
                    pdir = root;
                    
                    tmp1->sub=0;
                    tmp2->sub=0;
                    delete(tmp1);
                    delete(tmp2);
                }else if(pdir->father==0){
                    DIR* tmp1 = pdir;
                    root = pdir->sub;
                    if(pdir->sub){
                        pdir->sub->father=0;
                    }
                    pdir = root;   
                    
                    tmp1->sub=0;
                    delete(tmp1);
                }
            } else{
                pdir = pdir->sub;
            }
        }
        
        return root;
    }
    
    string simplifyPath(string path) {
        DIR *pdir = getSubPath(path,0);
        if(!pdir){
            return "/";
        }
        pdir = clearPath(pdir);
        if(!pdir){
            return "/";
        }
        stringstream ss;
        while(pdir){
            ss << "/" << pdir->name ;
            pdir = pdir->sub;
        }
        delete(pdir);
        return ss.str();
    }
};

//////////////////////
//这是用split解的，效率低些，代码简洁很多

vector<string> s_split(const string& in, const string& delim){
    regex re{delim};
    return vector<string>{
        sregex_token_iterator(in.begin(),in.end(),re,-1),
        sregex_token_iterator()
    };
}


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> segs = s_split(path,"/");
        vector<string> segs_new;
        
        for(auto &seg: segs){
            if(seg=="."){continue;}
            else if(seg==""){continue;}
            else if(seg==".."){if(!segs_new.empty()){segs_new.pop_back();}}
            else{segs_new.push_back(seg);}
        }
        if(segs_new.empty()){return "/";}
        
        stringstream ss;
        for(auto &seg: segs_new){
            ss << "/" << seg;
        }
        return ss.str();
    }
};
