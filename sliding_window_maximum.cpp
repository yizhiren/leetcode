

class MaxQue{

    deque<int> data;

    int maxData;

public:

    MaxQue()

    :maxData(INT_MIN){

        

    }

    void push(int x){

        data.push_back(x);

        if(x>maxData){

            maxData = x;

        }

    }

    

    void pop(){

        int top=data.front();

        data.pop_front();

        if(maxData==top){

            maxData = INT_MIN;

            deque<int>::iterator it;

            for(it=data.begin();it!=data.end();it++){

                if(maxData<*it)maxData=*it;

            }

        }

    }

    

    int getMax(){

        return maxData;

    }



};



class Solution {

public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        MaxQue que;

        vector<int> result;

        if(k==0)return result;

        for(int i=0;i<k;i++){

            que.push(nums[i]);

        }

        result.push_back(que.getMax());

        for(int i=k;i<nums.size();i++){

            que.push(nums[i]);

            que.pop();

            result.push_back(que.getMax());

        }

        return result;

        

    }

};


///////////////

class Window {
public:
    Window(vector<int>& _nums, int _k)
        :maxVal(INT_MIN)
        ,maxIndex(-1)
        ,nums(_nums)
        ,k(_k){}
    int maxVal;
    int maxIndex;
    vector<int>& nums;
    int k;
    
    void Rebuild(int startIndex) {
        maxVal=INT_MIN;
        maxIndex=-1;
        for(int i=startIndex;i<startIndex+k;i++){
            Push(nums[i],i);
        }
    }
    void Push(int val, int index){
        if(val > maxVal){
            maxVal = val;
            maxIndex = index;
        }
        if(index-k>=maxIndex){
            Rebuild(index-k+1);
        }
    }
    int GetMax() {
        return maxVal;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() <= 0){
            return vector<int>();
        }
        
        Window window(nums,k);
        window.Rebuild(0);
        vector<int> res;
        res.push_back(window.GetMax());
        for(int i=k;i<nums.size();i++){
            window.Push(nums[i],i);
            res.push_back(window.GetMax());
        }
        
        return res;
    }
};

