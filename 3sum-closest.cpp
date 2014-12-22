class Solution {
public:

    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()<=3){
        	vector<int>::iterator iter=num.begin();
        	int sum=0;
        	for(;iter!=num.end();iter++){
	        	sum+=*iter;
	        }
	        return sum;
        }
        int closestSum=9999;
        sort(num.begin(),num.end());
        int len=num.size();
        map<int,int> already;
        for(int i=0;i<len;i++){
        	int first = num[i];
        	if(already.find(first)==already.end()){
	        	already[first]=1;
	        }else{
        		continue;
        	}
        	int low=i+1;int high=len-1;
        	while(low<high){
	        	int sum=first+num[low]+num[high];
	        	if(abs(sum-target)==0){
	        		return target;
	        	}
	        	if(abs(sum-target)<abs(closestSum-target)){
	        		closestSum=sum;
	        	}
	        	if(sum>target){
	        		high--;
	        	}else{
	        		low++;
	        	}
	        }
        }
        return closestSum;
        
    }
};
