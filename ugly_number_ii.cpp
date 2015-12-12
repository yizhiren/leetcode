

#include <algorithm>



class Solution {

public:

    int nthUglyNumber(int n) {

        if(n<=1)return 1;

        vector<int> values;

        values.reserve(n);

        values.push_back(1);



        int base2=0;

        int base3=0;

        int base5=0;



        while(values.size()<n){

            int latest = values.back();



            int t_base2=base2;

            while(values[t_base2] * 2 <= latest)t_base2++;

            int v_next2 = values[t_base2] * 2;



            int t_base3=base3;

            while(values[t_base3] * 3 <= latest)t_base3++;

            int v_next3 = values[t_base3] * 3;



            int t_base5=base5;

            while(values[t_base5] * 5 <= latest)t_base5++;

            int v_next5 = values[t_base5] * 5;



            int vMin = min(v_next2, v_next3);

            vMin = min(vMin, v_next5);



            if(v_next2 == vMin)base2 = t_base2;

            if(v_next3 == vMin)base3 = t_base3;

            if(v_next5 == vMin)base5 = t_base5;



            values.push_back(vMin);

        }



        return values.back();

        return 0;

    }

};


