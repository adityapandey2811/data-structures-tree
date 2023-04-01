int getMaxWidth(Node* root) {
    queue<Node*> q;
    q.push(root);
    int maxWidth = 1;
    while(q.size()!=0){
        int n = q.size();
        for(int i=1;i<=n;i++){
            maxWidth = max(maxWidth,i);
            Node *temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return maxWidth;
}
