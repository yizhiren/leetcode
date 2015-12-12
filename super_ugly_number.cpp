#include <algorithm>



class Solution {

public:

    int nthSuperUglyNumber(int n, vector<int>& primes) {

        if(n<=1)return 1;

        vector<int> values;

        values.reserve(n);

        values.push_back(1);

        

        int primesNum = primes.size();

        vector<int> primeBase(primesNum, 0);

        while(values.size()<n){

            int latest = values.back();

            int min_next = INT_MAX;

            int min_next_base_index = -1;

            for(int i=0;i<primesNum;i++){

                int baseIndex = primeBase[i];

                while(values[baseIndex] * primes[i] <= latest)baseIndex++;

                

                primeBase[i] = (baseIndex==primeBase[i])?baseIndex:baseIndex-1;

                int thisValue = values[baseIndex] * primes[i];

                if(thisValue < min_next){

                    min_next = thisValue;

                    min_next_base_index = i;

                }

            }

            values.push_back(min_next);

            

            

        }

        return values.back();

    }

};






















