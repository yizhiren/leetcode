func maxmax(a,b int) int{
    if(a>b){
        return a;
    }
    return b
}

func getTreeHeight(root *TreeNode) int {
    if(root == nil){
        return 0
    }
    return maxmax(getTreeHeight(root.Left),getTreeHeight(root.Right)) + 1
}

func diameterOfBinaryTree(root *TreeNode) int {
    if(nil == root){return 0;}
        
    leftHeight := getTreeHeight(root.Left);
    rightHeight := getTreeHeight(root.Right);
        
    leftDiameter := diameterOfBinaryTree(root.Left);
    rightDiameter := diameterOfBinaryTree(root.Right);
        
    return maxmax(leftHeight+rightHeight, maxmax(leftDiameter,rightDiameter));
}
