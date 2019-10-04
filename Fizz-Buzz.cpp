class Solution {
public:
    string getString(int n){
        string str=to_string(n);
        if(n%15==0){
            str = "FizzBuzz";
        }else if(n%3==0){
            str = "Fizz";
        }else if(n%5==0){
            str = "Buzz";
        }
        
        return str;
    }
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        res.reserve(n);
        for(int i=1;i<=n;i++){
            res.push_back(getString(i));
        }
        
        return res;
    }
};
