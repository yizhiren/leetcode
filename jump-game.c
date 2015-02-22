
int canJump(int A[], int n) {
	int oneStepLongestIndex = 0;
	int twoStepLongestIndex = 0;
	for(int i=0;i<n;i++) {
		if(i>oneStepLongestIndex){
		    if(oneStepLongestIndex==twoStepLongestIndex)
		        return false;
		    else
			    oneStepLongestIndex=twoStepLongestIndex;
		}
		if(i+A[i]>twoStepLongestIndex){
			twoStepLongestIndex = i+A[i];
		}
		
	}
	return true;
}

