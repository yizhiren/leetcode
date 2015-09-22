/**
	if num is ABCDEFGHIJ
	1. assume X*YZ or XYZ or X*Y*Z are a whole,
	   then Answer(ABCDEFG) = Answer(ABCDEF) [+|-] (G)
					+ Answer(ABCDE) [+|-] (FG)
					+ Answer(ABCE) [+|-] (EFG)
					+ ...
					+ (ABCDEFG)
		this can be done by recursion
	2.  Whole(ABCDEFG) = Whole(ABCDEF) [*] G
					+ Whole(ABCDEF) [*] FG
					+ Whole(ABCDEF) [*] EFG
					+ ...
					+ ABCDEFG
		this can be done by recursion also.

    if you generate all possible expr then calc each expr this can work, but will timeout.
****/


const int INVALID_V = -9999;
using namespace std;

typedef long long LONG;
class Solution {
private:
	string numstring;
	int len;
	map<int,vector<pair<LONG,string> > > cache;
	map<pair<int,int>, vector<pair<LONG,string> > > cacheMulti;
	
	/**
	* convert from value to string
	*/
	string valueToString(LONG value){
		char v[20]={};
		snprintf(v,sizeof(v),"%d",value);
		return v;
	}
	

	/**
	* gene expr of single char number
	**/
	void geneMultiOfIndex(LONG index){
		int value = numstring[index]-'0';
		
		vector<pair<LONG,string> > currValue;
		pair<LONG,string> tmp(value,valueToString(value));
		currValue.push_back(tmp);
		
		pair<int,int> key(index,index);
		cacheMulti[key] = currValue;	
	}
	
	/**
	* check if this num is need to gene expr.
	**/
	bool checkIfNeedGeneThisNum(int curIdx, int rightIdx){
		return !(curIdx!=rightIdx && numstring[curIdx]=='0');
	}
	
	/*
		return the multi exprs from cache
	*/
	vector<pair<LONG,string> > &geneThenGetMultiValueFromRange(int left, int right){
		// gene the pre part that is needed.
		geneMultiOfRange(left,right);
		
	 	// get the pre part after generated.
		pair<int,int> preKey(left,right);
		return cacheMulti[preKey];		
	}
	
	/*
		gene (expr of left to right) * multiValue, and push back to currValue
	*/
	void pushCombineMultiValue(vector<pair<LONG,string> > left, LONG right, vector<pair<LONG,string> > &currValue){
		
		// combine left expr with right value
		for(int i=0;i<left.size();i++){
			pair<LONG,string> tmp;
			tmp.first = left[i].first * right;
			tmp.second = left[i].second + "*" + valueToString(right);
			currValue.push_back(tmp);
		}	
		
	}
	
	/**
	* gene expr of number from index 'left' to index 'right'
	*/
	void geneMultiOfRange(int left, int right) {
		pair<int,int> key(left,right);
		if(cacheMulti.find(key) != cacheMulti.end()){
			return;
		}
		if(left==right){
			geneMultiOfIndex(left);
			return;
		}
		if(left>right){
			return;
		}
		
		vector<pair<LONG,string> > currValue;
		LONG value = 0;
		int mul=1;		
		int rightcpy=right;
		while(left<rightcpy){
			// calc current value need to be multi
			value = mul*(numstring[rightcpy]-'0')+value;  mul *= 10;
			
			// check if this num should be skip
			if(!checkIfNeedGeneThisNum(rightcpy,right)){
				rightcpy--;
				continue;
			}			

			rightcpy--;
			
			vector<pair<LONG,string> > &preValue = geneThenGetMultiValueFromRange(left,rightcpy);
			pushCombineMultiValue(preValue, value, currValue);
		}
		if(checkIfNeedGeneThisNum(rightcpy,right)){
			value = mul*(numstring[rightcpy]-'0')+value;
			pair<LONG,string> tmp(value,valueToString(value));
			currValue.push_back(tmp);
		}
		
		cacheMulti[key] = currValue;
		
	}

	/*
		gene ans of only index 0
	*/
	void geneAnsOfFirstIndex(){
		int index=0;
		int value = numstring[index]-'0';
		
		vector<pair<LONG,string> > currValue;
		pair<LONG,string> tmp(value,valueToString(value));
		currValue.push_back(tmp);
		
		cache[index] = currValue;	
	}
	
	/*
		return the generated multi expr cache
	*/
	vector<pair<LONG,string> >& getMultiKeyOfRange(int left, int right){
		geneMultiOfRange(left,right);
		pair<int,int> mulKey(left,right);
		return cacheMulti[mulKey];
	}
	
	/**
	 combine left and right with '+' and '-'
	*/ 
	void pushConbimeAddExpr(vector<pair<LONG,string> > &left, vector<pair<LONG,string> > &right, vector<pair<LONG,string> > &currValue){
		for(int j=0;j<left.size();j++){
			for(int k=0;k<right.size();k++){
				pair<LONG,string> tmp;
				tmp.first=left[j].first + right[k].first;
				tmp.second = left[j].second + "+" + right[k].second;
				currValue.push_back(tmp);

				tmp.first=left[j].first - right[k].first;
				tmp.second = left[j].second + "-" + right[k].second;
				currValue.push_back(tmp);				
			}
			
		}
		
	}
	
	/**
		gene ans of  index 0-index
	*/
    void geneAnsOfIndex(int index) {
		if(cache.find(index) != cache.end()){
			return;
		}
		if(index >= len || index < 0){
			return;
		}		
		if(index==0){
			geneAnsOfFirstIndex();
			return;
		}

		int preIndex = index-1;
		// gene all ans of preindex
		geneAnsOfIndex(preIndex);
		
		vector<pair<LONG,string> > currValue;

		for(int i=index;i>=0;i--){
			
			// get the multi expr result from cache
			vector<pair<LONG,string> > &mulValue = getMultiKeyOfRange(i,index);
			
			if(i==0){
				// it meas there is no left part
				currValue.insert(currValue.begin(),mulValue.begin(),mulValue.end());
				continue;
			}
			// get the left part
			vector<pair<LONG,string> > &prePartValue = cache[i-1];
			
			pushConbimeAddExpr(prePartValue,mulValue,currValue)	;		
					
		}

		cache[index] = currValue;
	}
    
public:
    vector<string> addOperators(string num, int target) {
    	vector<string> result;
    	if(num=="") return result;    	
    	numstring = num;
		len = numstring.length();

		geneAnsOfIndex(len-1);
		
		vector<pair<LONG,string> > &value = cache[len-1];
		for(int i=0;i<value.size();i++){
			//std::cout<<value[i].first<<"<--->"<<value[i].second<<std::endl;
			if(value[i].first==target){
				result.push_back(value[i].second);
			}

		}
		
        return result;
    }
};

