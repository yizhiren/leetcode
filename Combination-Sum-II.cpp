class Solution {
	vector<vector<int> > result;
	vector<int> candidates;
	vector<int> candidateMultiNum;
	map<int,int> candidateMultiMax;

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
		int multi=candidateMultiMax[candidates[idx]];
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
    vector<vector<int> > combinationSum2(vector<int> &cs, int tar) {
		int len=cs.size();
        for(int i=0;i<len;i++){
            if(candidateMultiMax.find(cs[i])==candidateMultiMax.end()){
                candidateMultiMax[cs[i]] = 1;
            }else{
                candidateMultiMax[cs[i]]++;
            }
		}

		map<int,int>::iterator iter=candidateMultiMax.begin();
		for(;iter!=candidateMultiMax.end();iter++){
		    candidates.push_back(iter->first);
			candidateMultiNum.push_back(0);
		}
		sort(candidates.begin(),candidates.end());
		makeConbination(0,tar);
		return result;
    }
};
