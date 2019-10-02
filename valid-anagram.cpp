class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        
        map<char, int> store;
        for(auto ch:s){
            store[ch]++;
        }
        for(auto ch:t){
            if(store[ch]<=0){
                return false;
            }
            store[ch]--;
        }
        return true;
    }
};
