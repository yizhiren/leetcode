





/**

 * 

 * 

 * 1. 把值排序；同时记录原数组下标与排序第几的对应关系；这个也叫离散化，把原先范围为整个整数的输入变成排序的下标范围。后续可直接操作排序的序号，不必再去管原输入值。

 * 2. 按原数组下标顺序依次插入“树形数组”，并求已在树中的排序比它低的数个数；这个个数在每次插入时会更新每一个“树形数组”的父节点。

 * 3. 求已在树中的排序比它低的数个数，也是通过“树形数组”的标准操作，求和每一个管辖范围。

 * 

 * 

 * */

struct Node_Value_index{

    Node_Value_index(int index,int value)

    :index_from_orig(index),value_for_sort(value)

    {}

  int index_from_orig;

  int value_for_sort;

};



bool cmp(Node_Value_index & a, Node_Value_index & b){

    return a.value_for_sort < b.value_for_sort;

}



class Solution {



vector<Node_Value_index> value_seq_arr;

vector<int> index_seq_arr;

vector<int> index_cnt_arr;

vector<int> result;



    int lowestbit(int x){

        return x&-x;

    }

    

    int pre_seq(int x){

        return x-lowestbit(x);

    }

    

    int father_seq(int x){

        return x+lowestbit(x);

    }

    

    void update(int seq, int modify){

        while(seq < index_cnt_arr.size()){

            index_cnt_arr[seq] += modify;

            seq = father_seq(seq);

        }

    }

    

    int getSum(int seq){

        int sum=0;

        while(seq>0){

            sum+=index_cnt_arr[seq];

            seq = pre_seq(seq);

        }

        return sum;

    }



public:



    vector<int> countSmaller(vector<int>& nums) {

        int len=nums.size();

        if(0==len)return result;        

        

        index_cnt_arr.resize(len+1);  // all 0

        index_seq_arr.resize(len);

        result.resize(len);

        

        for(int i=0;i<len;i++){

            value_seq_arr.push_back(Node_Value_index(i,nums[i]));

        }

        sort(value_seq_arr.begin(), value_seq_arr.end(), cmp);

        

        for(int i=0;i<len;){

            int maybeSameSeqForSomeIndex = i;

            int currValue = value_seq_arr[i].value_for_sort;

            while(i<len && value_seq_arr[i].value_for_sort == currValue){

                index_seq_arr[value_seq_arr[i].index_from_orig] = maybeSameSeqForSomeIndex;

                i++;

            }

            

        }        

        

        

        for(int i=len-1;i>=0;i--){

            int seq = index_seq_arr[i];

            int seq_in_cnt = seq+1;

            result[i] = getSum(seq);

            update(seq_in_cnt,+1);

        }

        



        return result;

    }

};




