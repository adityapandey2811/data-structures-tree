int pathSum(TreeNode *root, int *res){
    if(!root) return 0;
    int l = pathSum(root->left,res);
    int r = pathSum(root->right,res);
    int temp = max(max(l,r) + root->val, root->val);
    int ans = max(temp, l+r+root->val);
    *res = max(*res, ans);
    return temp;
}
int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    pathSum(root, &res);
    return res;
}
