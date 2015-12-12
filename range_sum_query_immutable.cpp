class NumArray {

public:

    NumArray(vector<int> &nums)

    {

        int s = 0;

        for(int i=0;i<nums.size();i++){

            s+=nums[i];

            sum.push_back(s);

        }

    }









    int sumRange(int i, int j) {

        if(i>=0 && i<sum.size()

            && j>=0 && j<sum.size()

            && i<=j ){

                if(i==0){

                    return sum[j];

                }

                return sum[j]-sum[i-1];



            }

            return 0;

    }



    vector<int> sum;

};




