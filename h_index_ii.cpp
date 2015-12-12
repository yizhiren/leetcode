class Solution {

public:

    int hIndex(vector<int>& citations) {

        int len=citations.size();

        int hindex=0;

        for(int i=len-1;i>=0;i--){

            if(citations[i]>=len-i){

                hindex=len-i;

                continue;

            }

            break;

        }

        return hindex;

    }

};
