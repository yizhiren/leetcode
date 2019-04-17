
class Solution {
public:
    map<string, int> counts;
    queue<string> que;
    string dst;
    int kSimilarity() {
        size_t len = dst.length();

        while(!que.empty()){
            string src = que.front();
            que.pop();
            int changedCount = counts[src];
            if(src==dst){
                return changedCount;
            }

            vector<string> sublevel;
            for(int diffIndex=0;diffIndex<len;diffIndex++){
                //cout << "src=" << src << endl;
                //cout << "dst=" << dst << endl;
                
                if(src[diffIndex] != dst[diffIndex]){
                    int walkIndex = diffIndex;
                    while(++walkIndex<len){
                        if(src[walkIndex] == dst[walkIndex] || src[walkIndex] != dst[diffIndex]){
                            continue;
                        }
                        string src_copy = src;
                        swap(src_copy[diffIndex],src_copy[walkIndex]);
                        
                        if(src[diffIndex] == dst[walkIndex]){
                            sublevel.clear();
                            sublevel.push_back(src_copy);
                            break;
                        }
                        sublevel.push_back(src_copy);
                    }
                    break;
                }
            }
            for(auto &str: sublevel){
                if(counts.find(str) == counts.end()){
                    counts[str] = changedCount +1;
                    que.push(str);
                }
            }
            
        }
        return -1;
 
    }
    int kSimilarity(string A, string B) {
        dst = B;
        que.push(A);
        counts[A]=0;
        return kSimilarity();
    }
};
