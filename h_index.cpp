
ol cmp(int a,int b){

    return a>b;

}



class Solution {

public:

    int hIndex(vector<int>& citations) {

        int len=citations.size();

        sort(citations.begin(),citations.end(),cmp);

        

        int hindex = 0;

        for(int i=0;i<len;i++){

            if(citations[i]>=i+1){

                hindex = i+1;

                continue;

            }

            break;

        }

        return hindex;

    }

};
