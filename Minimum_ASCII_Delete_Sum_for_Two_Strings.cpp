const int MAX_LEN = 1001;
typedef int Table[MAX_LEN][MAX_LEN];

Table dynamic;
//Table direction;


class Solution {
public:
    string s1;
    string s2;
    int getCharSum(const string& str){
        int sum = 0;
        return accumulate(str.begin(), str.end(), sum);
    }
    
    void fillTable() {
        for(int j=0;j<=s2.length();j++){
            dynamic[0][j]=0;
        }
        for(int i=0;i<=s1.length();i++){
            dynamic[i][0]=0;
        }
        
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                int maxCharSum = max(dynamic[i-1][j],dynamic[i][j-1]);
                
                if(s1[i-1]==s2[j-1]){
                    maxCharSum = max(maxCharSum,dynamic[i-1][j-1]+s1[i-1]);
                }
                dynamic[i][j] = maxCharSum;
                //cout << dynamic[i][j] << ",";
            }
            //cout << endl;

        }
    }
    
    int minimumDeleteSum(string _s1, string _s2) {
        s1 = _s1;
        s2 = _s2;
        if(s1.length() == 0){
            return getCharSum(s2);
        }
        if(s2.length() == 0){
            return getCharSum(s1);
        }

        fillTable();
        return getCharSum(s1) + getCharSum(s2)
            - dynamic[s1.length()][s2.length()]
            - dynamic[s1.length()][s2.length()];
    }
};
