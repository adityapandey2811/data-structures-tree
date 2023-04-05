TreeNode* bst(vector<int>& v, int start, int end){
    if(start>end) return NULL;
    int mid = (start+end)/2;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = bst(v, start, mid-1);
    root->right = bst(v, mid+1, end);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return bst(nums,0,nums.size()-1);
}
