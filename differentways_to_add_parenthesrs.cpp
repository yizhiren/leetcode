
class Solution {

    int calcone(int a,char op,int b){

        if(op=='+'){

            return a+b;

        }else if(op=='-'){

            return a-b;

        }else{

            return a*b;

        }

    }

    int findFirstOp(string &input){

        int i=0;

        while(i<input.length()){

            if(input[i]=='+' || input[i]=='-' || input[i]=='*'){

                return i;

            }

            i++;

        }

        return -1;

    }

    

public:

    vector<int> diffWaysToCompute(string input) {

        //std::cout<<input<<std::endl;

        int len = input.length();

        vector<int> result;



        int i=findFirstOp(input);

        if(-1==i){

            result.push_back(atoi(input.c_str()));

            return result;

        }

        while(i<len){

            if(input[i]!='*' && input[i]!='+' && input[i]!='-'){

                i++;

                continue;

            }

            vector<int> tmp1 = diffWaysToCompute(input.substr(0,i));

            vector<int> tmp2 = diffWaysToCompute(input.substr(i+1,len-i-1));

            

            for(int b1=0;b1<tmp1.size();b1++){

                for(int b2=0;b2<tmp2.size();b2++){

                    result.push_back(calcone(tmp1[b1],input[i],tmp2[b2]));

                }

            }

            

            i+=2;

        }

    }

};
