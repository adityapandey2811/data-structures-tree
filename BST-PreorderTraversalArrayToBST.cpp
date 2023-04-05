TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return bst(preorder, i, INT_MAX);
}
TreeNode* bst(vector<int>& preorder, int &i, int bound){
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = bst(preorder, i, root->val);
    root->right = bst(preorder, i, bound);
    return root;
}
