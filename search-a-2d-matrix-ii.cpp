class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row<=0){return false;}
        int col = matrix[0].size();
        if (col<=0){return false;}
        
        int i = 0;
        int j = col-1;
        while(j>=0 && i<row) {
            while(matrix[i][j] < target && i+1 < row && matrix[i+1][j] <= target){
                i++;
            }
            //cout << matrix[i][j] << endl;
            if (matrix[i][j] == target){
                return true;
            }
            
            if (matrix[i][j] < target && i==row-1){
                return false;
            }
            
            j--;
        }
        
        return false;
    }
};

