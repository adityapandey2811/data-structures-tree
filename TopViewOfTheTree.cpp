vector<int> topView(Node *root){
    if(!root) return {};
    unordered_map<int, int> m;
    queue<pair<Node*, int>> q;
    int left = 0;
    q.push({root, 0});
    while(q.size()!=0){
        auto it = q.front();
        q.pop();
        int line = it.second;
        Node* temp = it.first;
        if(m.find(line) == m.end()) m[line] = temp->data;
        left = min(line,left);
        if(temp->left){
            q.push({temp->left, line-1});
        }
        if(temp->right){
            q.push({temp->right, line+1});
        }
    }
    vector<int> res;
    while(m.find(left)!=m.end()){ res.push_back(m[left++]); }
    return res;
}
