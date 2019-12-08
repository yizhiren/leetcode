/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    const vector<NestedInteger> &values;
    NestedIterator* iter;
    int idxValue;
    NestedIterator(const vector<NestedInteger> &nestedList) 
        :values(nestedList)
        ,idxValue(-1)
        ,iter(nullptr)
    {
       toNextIdx();
    }
    
    ~NestedIterator(){
        delete(iter);
    }    
    void toNextIdx() {
        while(1){
            idxValue ++;
            delete(iter);
            iter = nullptr;
            
            if(idxValue >= values.size()){
                break;
            }
            if(values[idxValue].isInteger()){
                break;
            }
            if(values[idxValue].getList().size()>0){
                iter =  new NestedIterator(values[idxValue].getList());
                if(iter->hasNext()){
                    break;
                }
            }
        }
    }

    int next() {
        auto &value=values[idxValue];
        if(value.isInteger()){
            toNextIdx();
            return value.getInteger();
        }else{
            int ret = iter->next();
            if(!iter->hasNext()){
                toNextIdx();
            }
            return ret;
        }
    }

    bool hasNext() {
        if(idxValue >= values.size()){
            return false;
        }
        auto &value=values[idxValue];
        if(value.isInteger()){
            return true;
        }
        
        if(iter == nullptr){
            iter = new NestedIterator(value.getList());
        }
        
        return iter->hasNext();   
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
