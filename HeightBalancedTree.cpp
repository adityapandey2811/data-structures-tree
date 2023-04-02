int isBalancedOrNot(TreeNode *root, int *res){
    int l,r;
    if(!root) return 0;
    else{
        l = isBalancedOrNot(root->left,res);
        r = isBalancedOrNot(root->right,res);
        if(l != r && l+1 !=r && r+1!=l){
            *res = -1;
        }
    }
    if(l>r){
        return l+1;
    }
    return r+1;
}
bool isBalanced(TreeNode* root) {
    int res = 0;
    isBalancedOrNot(root, &res);
    if(res == -1) return false;
    return true;
}
