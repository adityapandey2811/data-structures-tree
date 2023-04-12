// Optimal Solution
void inorder(TreeNode* root, int *res, int *k) {
    if(!root) return;
    if(*k != 0) {
        inorder(root->left,res,k);
    }
    if(*k != 0) {
        *k = *k-1;
        *res = root->val;
    }
    if(*k != 0) {
        inorder(root->right,res,k);
    }
}
int kthSmallest(TreeNode* root, int k) {
    int res = 0;
    inorder(root, &res, &k);
    return res;
}

// Bad Solution
void inorder(TreeNode* root, int k, priority_queue <int, vector<int>, greater<int> >& minHeap) {
    if(root == NULL) return;
    inorder(root->left, k, minHeap);
    minHeap.push(root->val);
    inorder(root->right, k, minHeap);
}
int kthSmallest(TreeNode* root, int k) {
    priority_queue <int, vector<int>, greater<int> > minHeap;
    inorder(root,k,minHeap);
    k--;
    while(k--){
        minHeap.pop();
    }
    return minHeap.top();
}
