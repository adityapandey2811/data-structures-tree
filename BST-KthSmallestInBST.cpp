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
