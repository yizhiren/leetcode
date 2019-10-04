
// 统计子串中字符个数不足k的字符，然后把子串切成更小的子串，进行递归
class Solution {
public:
    int longestSubstring(const string &s, int low, int high, int k) {
        cout << "sub," << low << "," << high << endl;
        if(low>high)return 0;
        
        map<char,int> counts;
        for(int i=low;i<=high;i++){
            counts[s[i]]++;
        }
        
        int res = 0;
        
        int st = low;
        bool allUsed=true;
        for(int i=low;i<=high;i++){
            if(counts[s[i]]<k){
                int subLen = longestSubstring(s,st,i-1,k);
                if(subLen > res){
                    res=subLen;
                }
                st = i+1;
                allUsed = false;
            }else if(!allUsed && i==high){
                int subLen = longestSubstring(s,st,i,k);
                if(subLen > res){
                    res=subLen;
                }
                st = i+1;
            }
        }
        if(allUsed){
            res = high-low+1;
        }
        
        
        return res;
    }
    
    int longestSubstring(string s, int k) {
        return longestSubstring(s,0,s.length()-1,k);
    }
};
