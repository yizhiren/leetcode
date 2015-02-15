class Solution {
	vector<vector<int> > result;
	vector<int> candidates;
	vector<int> candidateMultiNum;
	
	void addOneAnswer(int idx){
		vector<int> ans;
		for(int i=0;i<=idx;i++){
			int multi=candidateMultiNum[i];
			for(int j=0;j<multi;j++){
				ans.push_back(candidates[i]);
			}
		}
		result.push_back(ans);
	}
	
	void makeConbination(int idx,int tar){
		if((unsigned)idx>=candidates.size())return;
		int multi=tar/candidates[idx];
		for(int i=0;i<=multi;i++){
			candidateMultiNum[idx]=i;
			if(i*candidates[idx]==tar){
				//cout<<i<<"x"<<candidates[idx]<<endl;
				addOneAnswer(idx);
				break;
			}
			if(i*candidates[idx] > tar){
				break;
			}
			makeConbination(idx+1,tar-i*candidates[idx]);
		}
	}
public:
    vector<vector<int> > combinationSum(vector<int> &cs, int tar) {
        candidates = cs;
		int len=cs.size();
		for(int i=0;i<len;i++){
			candidateMultiNum.push_back(0);			
		}
		sort(candidates.begin(),candidates.end());
		makeConbination(0,tar);
		return result;
    }
};

