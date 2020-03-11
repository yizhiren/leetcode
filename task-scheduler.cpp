// 这个能拿到顺序
class Solution {
public:
    
    void clearBack(vector<char>& tasks){
        for(int i=tasks.size()-1;i>=0;i--){
            if(tasks[i]=='0'){
                tasks.pop_back();
            }else{
                break;
            }
        }
    }
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()){
            return 0;
        }
        
        map<char, int> count;
        for(auto ch:tasks){
            count[ch]++;
        }
        vector<pair<char,int>> taskvec(count.begin(),count.end());
        
        vector<char> seq;
        while(true){
            sort(taskvec.begin(),taskvec.end(),[](const pair<char,int>& a, const pair<char,int>& b){
                return a.second > b.second;
            });
            int len = taskvec.size();
            int nn = n;
            for(int i=0;i<len;i++){
                if(nn<0){
                    //一轮只收集n个防止浪费
                    break;
                }
                if(taskvec[i].second > 0){
                    seq.push_back(taskvec[i].first);
                    taskvec[i].second--;
                    nn--;
                }
            }
            if(nn==n){
                // 扫了一遍，没有新的了
                break;
            }
            while(nn>=0){
                seq.push_back('0');
                nn--;
            }
        }
        clearBack(seq);
        //cout << seq;
        return seq.size();
        
    }
};

// https://leetcode.com/problems/task-scheduler/solution/
// 这个不关注顺序，只要能填满(maxValue-1)*n的idle格子就肯定能排出顺序，所以只要计算idle格子能不能填满
class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()){
            return 0;
        }
        
        map<char, int> count;
        for(auto ch:tasks){
            count[ch]++;
        }
        vector<pair<char,int>> taskvec(count.begin(),count.end());
        sort(taskvec.begin(),taskvec.end(),[](const pair<char,int>& a, const pair<char,int>& b){
            return a.second > b.second;
        });        
        
        int maxIdle = (taskvec[0].second-1) * n;
        for(int i=1;i<taskvec.size();i++){
            maxIdle -= min(taskvec[i].second,taskvec[0].second-1); // 大于taskvec[0].second-1的部分不能用来填格子
        }
        
        return maxIdle<0?tasks.size():tasks.size()+maxIdle;
        
    }
};

