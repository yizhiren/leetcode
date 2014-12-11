class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> opposite;
        for(int i=0,len=numbers.size();i<len;i++){
        	opposite[target-numbers[i]] = i; 
        }
        for(int i=0,len=numbers.size();i<len;i++){
        	if(opposite.find(numbers[i]) != opposite.end()){
        		if(i == opposite[numbers[i]]){
		        	continue;
		        }
	        	vector<int> answer;
	        	answer.push_back(i+1);
	        	answer.push_back(opposite[numbers[i]]+1);
	        	return answer;
	        }
        }
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> opposite;
        for(int i=0,len=numbers.size();i<len;i++){
        	if(opposite.find(numbers[i]) != opposite.end()){
        		vector<int> answer;	        	
	        	answer.push_back(opposite[numbers[i]]+1);
	        	answer.push_back(i+1);
	        	return answer;
	        }else
        		opposite[target-numbers[i]] = i; 
        }

    }
};