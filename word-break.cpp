class Solution {
public:
 
    map<int, bool> cache;
    
    bool wordBreak(string& s, int index,vector<string>& wordDict) {
        if(cache.find(index) != cache.end()){
            return cache[index];
        }
        if(index>=s.length()){
            return true;
        }
        
        for(int i=0;i<wordDict.size();i++){
            const string& word = wordDict[i];
            int wordLen = word.length();
            if ( index + wordLen <= s.length()){
                if(s.substr(index,wordLen) == word){
                    if(wordBreak(s,index+wordLen,wordDict)){
                        return true;
                    }
                }
            }
        }
        
        cache[index] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()){
            return true;
        }
        return wordBreak(s,0,wordDict);
    }
};
