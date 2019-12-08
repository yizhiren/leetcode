

class Solution {
    map<int, bool> visiting;
    map<int, bool> visited;
    
    vector<vector<int>> nodeList;
    vector<int> res;
	bool checkPrerequire(int idx){
        if(visited.find(idx) != visited.end()){
            return true;
        }
        if(visiting[idx]){
            return false;
        }
        visiting[idx]=true;
        
		vector<int> &needednodes = nodeList[idx];
		int preLen=needednodes.size();
		for(int i=0;i<preLen;i++){
            int toVisit = needednodes[i];
			if(!checkPrerequire(toVisit)){
				return false;
			}
		}
        
        visiting[idx]=false;
        
        visited[idx]=true;
        res.push_back(idx);
		return true;
	}
	void makePrerequire(vector<vector<int> >& prerequisites){
		int len=prerequisites.size();
		for(int i=0;i<len;i++){
			nodeList[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
	}
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        nodeList.resize(numCourses);
        makePrerequire(prerequisites);
        for(int i=0;i<numCourses;i++){
        	if(!checkPrerequire(i)){
	        	return vector<int>();
	        }
        }
        
        return res;
    }
    
};
