/*and 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, int start, vector<int>& cost) {
        int left=0;
        for(int i=0;i<gas.size();i++){
            int index = (start+i) % gas.size();
            left = left + gas[index]-cost[index];
            if(left<0){
                return false;
            }
        }
        return true;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            if(canCompleteCircuit(gas,i,cost)){
                return i;
            }
        }
        
        return -1;
    }
};
*/

class Solution {
public:    
    // 肯定从某一个不满足初始条件的节点后的某个节点开始
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;int totalSum=0;int pos=0;
        for(int i=0;i<gas.size();i++){
            curSum += gas[i]-cost[i];
            if(curSum<0){
                curSum=0;
                pos = (i+1)%gas.size();
            }
            totalSum += gas[i]-cost[i];
        }

        return totalSum >=0 ? pos:-1;
    }
};
