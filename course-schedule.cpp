struct Node{
	Node(){
		canGet=false;
		inLink=false;
	}
	bool canGet;
	bool inLink;
	vector<int> neededNodes;	
};

class Solution {
	vector<Node> nodeList;
	bool checkPrerequire(int idx){
		if(nodeList[idx].inLink){
			return false;
		}
		if(nodeList[idx].canGet){
			return true;
		}
		vector<int> &needednodes = nodeList[idx].neededNodes;
		nodeList[idx].inLink = true;
		int preLen=needednodes.size();
		for(int i=0;i<preLen;i++){
			if(!checkPrerequire(needednodes[i])){
				return false;
			}
		}
		nodeList[idx].inLink = false;
		nodeList[idx].canGet = true;
		return true;
	}
	void makePrerequire(vector<vector<int> >& prerequisites){
		int len=prerequisites.size();
		for(int i=0;i<len;i++){
			nodeList[prerequisites[i][0]].neededNodes.push_back(prerequisites[i][1]);
		}
	}
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        nodeList.resize(numCourses);
        makePrerequire(prerequisites);
        for(int i=0;i<numCourses;i++){
        	if(!checkPrerequire(i)){
	        	return false;
	        }
        }
        return true;
    }
};

