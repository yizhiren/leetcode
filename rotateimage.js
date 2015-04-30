/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var len=matrix.length;
    if(len<=1){
        return;
    }
    var loopLineNum = parseInt((len+1)/2);
    for(var i=0;i<loopLineNum;i++){
        for(var j=i;j<len-1-i;j++){
            exchangeNode(matrix,i,j);
        }
    }
    
};

var exchangeNode = function(matrix,i,j) {
    var len=matrix.length;
    var tmp=matrix[i][j];
    matrix[i][j] = matrix[len-1-j][i];
    matrix[len-1-j][i] = matrix[len-1-i][len-1-j];
    matrix[len-1-i][len-1-j] = matrix[j][len-1-i];
    matrix[j][len-1-i] = tmp;
    
}



