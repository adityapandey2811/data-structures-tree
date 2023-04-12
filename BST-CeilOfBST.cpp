int findCeil(Node* root, int x) {
    int f = INT_MAX;
    int max = INT_MAX;
    while(root){
        if(root->data >= x){
            max = root->data;
            if(f>max) {
                f = max;
            }
            root = root->left;
        } else {
            root = root->right;
        }
    }
    if(f == INT_MAX) return -1;
    return f;
}
