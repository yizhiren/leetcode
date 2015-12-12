class Solution {

    vector<int> s;

public:

    int countDigitOneOfDeep(int n, int deep, int left){

        //cout<<"countDigitOneOfDeep."<<n<<"."<<deep<<endl;

        //if(1==deep){

          //  return n>=1?1:0;

        //}

        int s1=s[deep-1]*n;

        int s2=(n>1)?pow(10,deep-1):0;

        int s3=(n==1)?left+1:0;

        return s1+s2+s3;

    }



    Solution(){

        const int max_len = 10;

        s.resize(max_len);

        s[0]=0;

        for(int i=1;i<max_len;i++){

            s[i] = countDigitOneOfDeep(10,i,-1);

            //std::cout<<"s."<<i<<"="<<s[i]<<endl;

        }

    }



    int countDigitOne(int n) {

        int sm=0;

        if(n<=0)return 0;

        while(n){

            int tmp=1;

            int deep=1;

            while(n/tmp>=10){tmp*=10;deep++;}



            int head = n/tmp;

            int tail = n%tmp;

            //std::cout<<head<<","<<tail<<"."<<tmp<<"."<<deep<<std::endl;

            sm+=countDigitOneOfDeep(head, deep ,tail);

            n=tail;

        }



        return sm;

    }





};
