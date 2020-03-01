typedef list<int>::iterator ListIter;
typedef pair<int, ListIter> MapValue;
typedef map<int,MapValue>::iterator MapIter;

class LRUCache {
public:
    list<int> m_list;
    map<int,MapValue> m_cache;
    int m_capacity;
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    void updateList(int key){
        auto listIter = m_cache[key].second;
        m_list.erase(listIter);
        m_list.push_front(key);
        m_cache[key].second = m_list.begin();
    }
    
    void checkCapacity(){
        if(m_list.size() > m_capacity){
            int key = m_list.back();
            m_cache.erase(key);
            m_list.pop_back();
        }
    }
    
    bool ExistKey(MapIter& mapIter){
        return mapIter != m_cache.end();
    }
    
    int get(int key) {
        auto mapIter = m_cache.find(key);
        if(ExistKey(mapIter)){
            int value = mapIter->second.first;
            updateList(key);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto mapIter = m_cache.find(key);
        if(ExistKey(mapIter)){
            mapIter->second.first = value;
            updateList(key);
            return;
        }
        m_list.push_front(key);
        m_cache[key] = MapValue(value,m_list.begin());
        checkCapacity();
    }
};
