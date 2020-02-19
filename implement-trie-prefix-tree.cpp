class Trie {
public:
    vector<Trie*> subLevel;
    /** Initialize your data structure here. */
    Trie() {
        for(int i=0;i<26;i++){
            subLevel.push_back(nullptr);
        }
        subLevel.push_back(nullptr);
    }
    
    ~Trie(){
        for(int i=0;i<26;i++){
            delete subLevel[i];
        }
        delete subLevel[26];
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // assume word are only a-z
        if(word.empty()){
            if(subLevel[26] == nullptr){
                subLevel[26] = new Trie();
            }
        } else {
            char ch = word[0];
            if(subLevel[ch-'a']==nullptr){
                subLevel[ch-'a'] = new Trie();
            }
            subLevel[ch-'a']->insert(word.substr(1));
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        // assume word are only a-z
        if(word.empty()){
            return (subLevel[26] != nullptr);
        } else {
            char ch = word[0];
            if(subLevel[ch-'a']==nullptr){
                return false;
            }
            return subLevel[ch-'a']->search(word.substr(1));
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // assume word are only a-z
        if(prefix.empty()){
            return true;
        } else {
            char ch = prefix[0];
            if(subLevel[ch-'a']==nullptr){
                return false;
            }
            return subLevel[ch-'a']->startsWith(prefix.substr(1));
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
