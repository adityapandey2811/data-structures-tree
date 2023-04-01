void getPath(TreeNode *root, int x, int *k, vector<int>& v){
    if(!root){
        return;
    }
    if(root->val == x){
        *k = 1;
    }
    if(*k != 1)
        getPath(root->left,x,k,v);
    if(*k != 1)
        getPath(root->right,x,k,v);
    if(*k == 1){
        v.push_back(root->val);
        return;
    }
}
vector<int> solve(TreeNode* root, int x) {
    int k = 0;
    vector<int> v;
    getPath(root,x, &k, v);
    reverse(v.begin(),v.end());
    return v;
}
