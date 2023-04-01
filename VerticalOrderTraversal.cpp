vector<vector<int>> vecticalTraversal(TreeNode* root){
  if(!root) return {{}};
  unordered_map<int, vector<int>> m;
  queue<pair<TreeNode*, int>> q;
  q.push({root, 0});
  int left = 0;
  while(q.size()!=0){
      auto it = q.front();
      q.pop();
      TreeNode *temp = it.first;
      int line = it.second;
      left = min(line, left);
      m[line].push_back(temp->val);
      if(temp->left){
          q.push({temp->left,line-1});
      }
      if(temp->right){
          q.push({temp->right,line+1});
      }
  }
  vector<vector<int>> res;
  while(m.find(left)!=m.end()){ res.push_back(m[left++]); }
  return res;
}
