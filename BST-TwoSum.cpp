void inorder(TreeNode* root, bool *res, unordered_map<int,int>& mp, int k) {
    if(!root) return;
    if(*res != true) {
        inorder(root->left, res, mp, k);
    }
    if(mp.find(k - root->val) != mp.end()){
        *res = true;
    } else {
        mp[root->val] = 1;
    }
    if(*res != true) {
        inorder(root->right, res, mp, k);
    }
}
bool findTarget(TreeNode* root, int k) {
    unordered_map<int,int> mp;
    bool res = false;
    inorder(root, &res, mp, k);
    return res;
}
