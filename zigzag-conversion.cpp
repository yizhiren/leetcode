class Solution {
public:
	int getNextOne(int low,int high,int theline,bool down){
		if(down){
			//down
			return (high-theline)*2;
		}else{
			//up
			return (theline-low)*2;
		}
	}
    string convert(string s, int nRows) {
    	if (nRows==1){
	    	return s;
	    }
    	int len=s.length();
    	string ret;
        for(int i=0;i<nRows;i++){
        	int curr=i; 
			bool downdirect = true;
			if(curr < len){
  				ret+=s[curr];			       	
  			}else{
				continue;  	
	  		}   	
        	while(1){
	        	int nextone=getNextOne(0,nRows-1,i,downdirect);
	        	if(nextone>0){
	        		curr+=nextone;
					if(curr < len){
		  				ret+=s[curr];			       	
		  			}else{
						break;  	
			  		}        		
	        	}
	        	downdirect=!downdirect;
	        }
        }
        return ret;
    }
};
