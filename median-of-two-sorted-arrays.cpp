class Solution {

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int *arrlong;int longnum;
        int *arrshort;int shortnum;
        arrlong=m>n?A:B;longnum=m>n?m:n;
        arrshort=m>n?B:A;shortnum=m>n?n:m;
        
        int half=(longnum+shortnum)/2;int ed=half;int st=half-shortnum;
        if(shortnum==0){
        	return (m+n)%2==0?(arrlong[longnum/2-1]+arrlong[longnum/2])/2.0:arrlong[longnum/2];
        }
        if(st==0){
        	if(arrshort[shortnum-1]<=arrlong[0]){
	        	return (m+n)%2==0?(arrshort[shortnum-1]+arrlong[0])/2.0:arrlong[0];
	        }else{
        		st==1;
        	}
        }else{
        	if(arrshort[shortnum-1]<=arrlong[st]){
        		int litpart=arrshort[shortnum-1]>arrlong[st-1]?arrshort[shortnum-1]:arrlong[st-1];
	        	return (m+n)%2==0?(litpart+arrlong[st])/2.0:arrlong[st];
	        }else{
        		st++;
        	}
        }
        if(arrlong[ed-1]<=arrshort[0]){
        	int bigpart=ed<longnum?(arrshort[0]<arrlong[ed]?arrshort[0]:arrlong[ed]):arrshort[0];
        	return (m+n)%2==0?(arrlong[ed-1]+bigpart)/2.0:bigpart;
        }
        while(st<=ed){
        	int mid=(st+ed)/2;
        	int shortlit=half-mid;
        	
        	if(arrshort[shortlit-1]>arrlong[mid]){
	        	st=mid+1;
	        	continue;
	        }
	        
	        if(arrlong[mid-1]>arrshort[shortlit]){
        		ed=mid-1;
        		continue;
        	}
        	
        	if((m+n)%2==0){
	        	int litpart=arrshort[shortlit-1]<arrlong[mid-1]?arrlong[mid-1]:arrshort[shortlit-1];
	        	int bigpart=arrshort[shortlit]<arrlong[mid]?arrshort[shortlit]:arrlong[mid];
	        	return (litpart+bigpart)/2.0;
	        }else{
        		return arrshort[shortlit]<arrlong[mid]?arrshort[shortlit]:arrlong[mid];
        	}
	        
        }
        
    }
};

