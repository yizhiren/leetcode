class Solution {
public:
    int value(char ch){
        return (ch=='1')?1:-1;
    }
    
    //内部山脚（山谷）
    int getSecondFoot(const string& str){
        int minfoot = numeric_limits<int>::max();
        int foot = 0;
        size_t len = str.length();
        for(int i=0;i<len;i++){
            foot += value(str[i]);
            //cout << "ch=" << str[i] << ",value="  << value(str[i]) << endl;
            if(i+1<len && foot < minfoot &&
               str[i]=='0' && str[i+1]=='1'){
                minfoot = foot;
            }
        }
        
        return minfoot;
    }
    
    vector<string> cutMontains(string sequence, int foot) {
        size_t len = sequence.length();
        vector<string> vec;
        // 头部
        string head(foot,'1');
        // 尾部
        string tail(foot,'0');
        // 头部是第一项
        vec.push_back(head);
        
        // 去头去尾
        sequence = sequence.substr(foot, len-foot-foot);
        
        string section;
        int sum = 0;
        len =sequence.length();
        for(int i=0;i<len;i++){
            char ch = sequence[i];
            section.append(1,ch);
            sum += value(ch);
            if(sum==0){
                // 遇到山谷，行程一个山，山递归调用
                vec.push_back(makeLargestSpecialImpl(section));
                // 重新累计
                section.clear();
            }
        }
        // 尾部是最后一项
        vec.push_back(tail);
        
        return vec;
    }
    
    string makeLargestSpecialImpl(string& sequence) {
        // 计算中间的山谷高度
        int foot = getSecondFoot(sequence);
        if(foot == numeric_limits<int>::max()){
            // 没有山谷
            return sequence;
        }
        
        // 按照山谷分成几段
        vector<string> sections = cutMontains(sequence, foot);
        auto st = sections.begin(); advance(st,1);
        auto ed = sections.end(); advance(ed,-1);
        // 每一段山谷排序
        sort(st,ed, [](const string& a, const string& b){
            return a>b;
        });
        
        // 起终段和山谷段串联起来
        return accumulate(sections.begin(), sections.end(), string(""));
    }
    
    string makeLargestSpecial(string S) {
        return makeLargestSpecialImpl(S);;
    }
};
