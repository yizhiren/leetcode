class RandomizedSet {
public:
    vector<int> vecset;
    unordered_map<int,int> hashset;
    default_random_engine random;
    
    int generateRand(int low, int high){
        
        uniform_int_distribution<int> dist(low,high);
        return dist(random);
    }

    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto iter = hashset.find(val);
        if(iter!=hashset.end()){
            return false;
        }
        hashset[val]=vecset.size();
        vecset.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = hashset.find(val);
        if(iter==hashset.end()){
            return false;
        }
        int idx = iter->second;
        
        swap(vecset[idx],vecset[vecset.size()-1]);
        hashset[vecset[idx]]=idx;
        
        hashset.erase(iter);
        vecset.pop_back();
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(vecset.size() <= 0){
            return 0;
        }
        return vecset[generateRand(0,vecset.size()-1)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
