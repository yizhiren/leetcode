class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int> > charStack;
        int len=s.length();
		for(int i=0;i<len;i++){
			if(s[i]=='('){
				pair<char,int> charPair(s[i],i);
				charStack.push(charPair);
				continue;
			}
			if(!charStack.empty() && charStack.top().first=='('){
				int leftPlace=charStack.top().second;
				s[leftPlace]='.';
				s[i]='.';
				charStack.pop();
				continue;
			}			
		}
		int maxLen=0;
		int currLen=0;
		for(int i=0;i<len;i++){
			cout<<s[i];
			if(s[i]!='.'){
				if(currLen > maxLen){
					maxLen=currLen;
				}
				currLen=0;
			}else{
				currLen++;
			}
		}
		cout<<endl;
		return max(maxLen,currLen);

        
    }
};