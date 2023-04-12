void inorder(Node* root, int *res, int *k) {
    if(!root) return;
    if(*k != 0) {
        inorder(root->right,res,k);
    }
    if(*k != 0) {
        *k = *k-1;
        *res = root->data;
    }
    if(*k != 0) {
        inorder(root->left,res,k);
    }
}
int kthLargest(Node* root, int k) {
    int res = 0;
    inorder(root, &res, &k);
    return res;
}
