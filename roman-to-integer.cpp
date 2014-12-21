class Solution {
public:
    int romanToInt(string s) {
    	int result = 0;
    	int len=s.length();
    	
   		map<char, int> romanNumber;
    	string romanChar="IVXLCDM";
    	
    	romanNumber['I'] = 1;
    	romanNumber['V'] = 5;
    	romanNumber['X'] = 10;
    	romanNumber['L'] = 50;
    	romanNumber['C'] = 100;
    	romanNumber['D'] = 500;
    	romanNumber['M'] = 1000;
    	
    	int i=0;
    	while(i<len){
	    	int pos=romanChar.find(s[i]);
	    	if(i+1>=len){
	    		result+=romanNumber[romanChar[pos]];
	    		i++;
	    	}else{
	    		int pos2=romanChar.find(s[i+1]);
	    		if(pos2-pos==1 || pos2-pos==2){
		    		result+=(romanNumber[romanChar[pos2]] - romanNumber[romanChar[pos]]);
		    		i=i+2;
		    	}else{
	    			result+=romanNumber[romanChar[pos]];
	    			i++;
	    		}
	    	}
	    	
	    }
	    return result;
    }
};