

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
