int jump(int A[], int n) {
	
	int oneStepLongestIndex = 0;
	int twoStepLongestIndex = 0;
	int stepNumber = 0;
	for(int i=0;in;i++) {
		if(ioneStepLongestIndex){
			stepNumber++;
			oneStepLongestIndex=twoStepLongestIndex;
		}
		if(i+A[i]twoStepLongestIndex){
			twoStepLongestIndex = i+A[i];
		}
		
	}
	return stepNumber;
}
