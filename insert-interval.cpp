/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        //sort(intervals.begin(),intervals.end(),comparestruct);
        int i=0;int len=intervals.size();vector<Interval> result;
        if(len==0)return result;
        while(i<len-1){
            Interval &obj1=intervals[i];
            Interval &obj2=intervals[i+1];
            if(obj1.end>=obj2.start){
                obj2.start=obj1.start;
                obj2.end=max(obj1.end,obj2.end);
            }else{
                result.push_back(obj1);
            }
            i++;
        }
        result.push_back(intervals[len-1]);
        
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int len=intervals.size();
        intervals.push_back(newInterval);//resize it, whatever be pushed
        for(int i=len-1;i>=0;i--){
            if(intervals[i].start>newInterval.start){
                intervals[i+1]=intervals[i];
            }else{
                intervals[i+1]=newInterval;
                break;
            }
            if(i==0){
                intervals[0]=newInterval;
            }
        }
        return merge(intervals);
        
    }
};