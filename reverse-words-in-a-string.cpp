class Solution {
public:
    void reverseWords(string &s) {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ")+1);
        
        int len=s.length();
        string revstr;
        revstr.resize(len);
        
     	int left=0;
     	int revright=len;
		
		int right=s.find(' ',left);	   
  		while(right!=string::npos){
			int wordlen=right-left;
			for(int i=0;i<wordlen;i++){
				revstr[revright-wordlen+i]=s[left+i];	
			}
			if(wordlen > 0){
			    revright=revright-wordlen-1;
			    revstr[revright]=' ';
			}
			left=right+1;
			right=s.find(' ',left);				
  		}
  		int wordlen=len-left;
		for(int i=0;i<wordlen;i++){
			revstr[revright-wordlen+i]=s[left+i];	
		}
		revstr.erase(0,revright-wordlen);
		s=revstr;	
    }
};
