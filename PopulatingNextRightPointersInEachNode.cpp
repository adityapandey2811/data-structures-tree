Node* connect(Node* root) {
    if(!root) return NULL;
    queue<Node*> q;
    q.push(root);
    while(q.size()!=0){
        int n = q.size();
        Node* prev = NULL;
        for(int i = 0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            if(i+1 == n) {
                if(prev!=NULL) prev->next = temp;
                temp->next = NULL;
            } else if(i != 0) {
                prev->next = temp;
            }
            prev = temp;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return root;
}
