class Solution {
public:

    string intToRoman(int num) { // num : 1-3999
    	string ge[10]={
			"","I","II","III","IV","V","VI","VII","VIII","IX" 
		};
		string shi[10]={
			"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" 
		};
		string bai[10]={
			"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" 
		};
		string qian[4]={
			"","M","MM","MMM"
		};
        string result="";
        int geNum=num%10; 
        num=num/10;
        int shiNum=num%10;
        num=num/10;
        int baiNum=num%10;
        num=num/10;
        int qianNum=num%10;
        num=num/10;
        result +=qian[qianNum];
        result +=bai[baiNum];
        result +=shi[shiNum];
        result +=ge[geNum];
        return result;
    }
};