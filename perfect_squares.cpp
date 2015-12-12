



class Solution {

public:

    int *pi;

    vector<int> vec;

    int calc(int n){

        if(n==0)return 0;

        if(pi[n]!=0)return pi[n];



        int mincnt=INT_MAX;

        int i=0;

        while(i<vec.size() && vec[i]<=n){

             int cnt_a=calc(vec[i]);

             if(cnt_a>=mincnt){

                 i++;

                 continue;

             }

             int cnt_b=calc(n-vec[i]);

             

             //std::cout<<vec[i]<<"=";

             //std::cout<<cnt_a<<"=";

             //std::cout<<cnt_b<<std::endl;

 

             if(cnt_a+cnt_b<mincnt){

                 mincnt=cnt_a+cnt_b;

             }

             i++;

        }

        pi[n]=mincnt;

        return mincnt;

    }

    int numSquares(int n) {

        int memsize=sizeof(int)*(n+1);

        pi=(int*)malloc(memsize);

        memset(pi,0,memsize);

        int i=1;

        while(i*i<=n){

            pi[i*i]=1;

            vec.push_back(i*i);

            i++;

        }

        int cnt=calc(n);

        free(pi);

        return cnt;

        

    }

};
