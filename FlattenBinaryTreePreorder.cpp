void justDoIt(TreeNode* root, TreeNode** prev){
    if(!root) return;
    // (*prev) = root;
    justDoIt(root->right, prev);
    justDoIt(root->left, prev);
    root->right = (*prev);
    root->left = NULL;
    (*prev) = root;
}
void flatten(TreeNode* root) {
    TreeNode *prev = NULL;
    justDoIt(root,&prev);
}
