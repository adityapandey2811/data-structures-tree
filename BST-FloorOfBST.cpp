int floor(Node* root, int x) {
    int f = INT_MIN;
    int min = INT_MIN;
    while(root){
        if(root->data <= x){
            min = root->data;
            if(f<min) {
                f = min;
            }
            root = root->right;
        } else {
            root = root->left;
        }
    }
    if(f == INT_MIN) return -1;
    return f;
}
