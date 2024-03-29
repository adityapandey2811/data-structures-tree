//Optimised O(N) Time
vector <int> bottomView(Node *root) {
    if(root == NULL) return {};
    unordered_map<int, int> m;
    int left = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(q.size()!=0){
        auto it = q.front();
        q.pop();
        Node *temp = it.first;
        int line = it.second;
        m[line] = temp->data;
        left = min(left,line);
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

//Not Optimal O(N*Log(N)) Time
vector <int> bottomView(Node *root) {
    if(root == NULL) return {};
    map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(q.size()!=0){
        auto it = q.front();
        q.pop();
        Node *temp = it.first;
        int line = it.second;
        m[line] = temp->data;
        if(temp->left){
            q.push({temp->left, line-1});
        }
        if(temp->right){
            q.push({temp->right, line+1});
        }
    }
    vector<int> res;
    for(auto it: m){
        res.push_back(it.second);
    }
    return res;
}
