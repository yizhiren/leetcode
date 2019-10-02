class MedianFinder {
public:
    /** initialize your data structure here. */
    
    map<int,int> stream;
    int count;
    
    MedianFinder() {
        stream.clear();
        count = 0;
    }
    
    void addNum(int num) {
        stream[num] ++;
        count ++;
    }
    
    double findMedian() {
        if (count==0)return 0;
        
        int nth = count/2 + count%2;
        double res = 0;
        
        
        int walkCount = 0;
        auto iter = stream.begin();
        while(iter != stream.end()){
            int k = iter->first;
            int v = iter->second;
            walkCount += v;
            if (walkCount >= nth) {
                res = k;
                if(count%2==0){
                    if (walkCount>nth){
                        // nothing   
                    } else {
                        res = (res+((++iter)->first))/2;
                    }
                }
                return res;
            }
            iter++;
        }
        
        return res;
    }
};


//////////////////////

class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int> > big;
    double median;
    
    MedianFinder() {
        priority_queue<int>().swap(small);
        priority_queue<int,vector<int>,greater<int> >().swap(big);
        median = 0;
    }
    
    void addNum(int num) {
        if(small.size() < big.size()){
            if (num <= median){
                small.push(num);
            } else {
                small.push(big.top());
                big.pop();
                big.push(num);
            }
            median = (small.top()+big.top())/(2.0);
        } else if(small.size() == big.size()){
            if (num <= median){
                small.push(num);
                median = small.top();
            } else {
                big.push(num);
                median = big.top();
            }

        } else if(small.size() > big.size()){
            if (num <= median){
                big.push(small.top());
                small.pop();
                small.push(num);
            } else {
                big.push(num);
            }
            median = (small.top()+big.top())/(2.0);
        }
        
    }
    
    double findMedian() {
        return median;
    }
};
