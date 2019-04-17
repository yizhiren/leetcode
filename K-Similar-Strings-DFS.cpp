#define RETURN_IF_EQUAL(X,Y,Z) if(X==Y){return Z;}

class Solution {
public:
    map<string, int> counts;
    string dst;
    int kSimilarity(string &src) {
        RETURN_IF_EQUAL(src,dst,0);
        
        if(counts.find(src) != counts.end()){
            return counts[src];
        }
        
        size_t len = src.length();
        int resMin = 999999;
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
                    int res = 1 + kSimilarity(src_copy);
                    
                    if(src[diffIndex] == dst[walkIndex]){
                        counts[src] = res;
                        return res;
                    }
                    if(res < resMin){
                        resMin = res;
                    }
                }
                break;
            }
        }
        counts[src] = resMin;
        return resMin;
    }
    int kSimilarity(string A, string B) {
        dst = B;
        return kSimilarity(A);
    }
};
