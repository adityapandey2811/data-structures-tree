class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "n";
        queue<TreeNode*> q;
        q.push(root);
        string str = "";
        str += to_string(root->val);
        str += "/";
        while(q.size()!=0){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    str += to_string(temp->left->val);
                    str += "/";
                } else{
                    str += "n";
                }
                if(temp->right){
                    q.push(temp->right);
                    str += to_string(temp->right->val);
                    str += "/";
                } else{
                    str += "n";
                }
            }
        }
        cout<<str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v;
        int i=0;
        cout<<data<<endl;
        while(i<data.size()){
            int flag = 0;
            string str = "";
            while(data[i]!='/' && i<data.size()){
                if(data[i] == 'n'){
                    v.push_back(INT_MIN);
                }
                else if(data[i] == '-'){
                    flag = 1;
                }
                else
                    str += data[i];
                i++;
            }
            i++;
            if(str.size() == 0) break;
            if(flag == 1){
                if(str.size() == 1)
                    v.push_back(-1 * (int(str[0]) - 48));
                else
                    v.push_back(-1 * stoi(str));
            }
            else{
                if(str.size() == 1)
                    v.push_back(int(str[0]) - 48);
                else
                    v.push_back(stoi(str));
            }
            // cout<<str<<" ";
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i] == INT_MIN) cout<<"n"<<" ";
            else cout<<v[i]<<" ";
        }
        cout<<endl;
        return constructbt(v);
    }


private:
    TreeNode* constructbt(vector<int> v){
        if(v[v.size()-1] == INT_MIN) return NULL;
        TreeNode *temp = NULL;
        queue<TreeNode*> head;
        temp = new TreeNode(v[v.size()-1]);
        v.pop_back();
        head.push(temp);
        while(head.size()!=0){
            TreeNode *parent = head.front(),*leftc = NULL, *rightc = NULL;
            head.pop();
            int n;
            cout<<parent->val<<" ";
            if(v.size()!=0){
                n = v[v.size()-1];
                v.pop_back();
                cout<<n<<" ";
            }
            else
                return temp;
            
            if(n!=INT_MIN){
                leftc = new TreeNode(n);
                parent->left = leftc;
                head.push(leftc);
            }

            if(v.size()!=0){
                n = v[v.size()-1];
                v.pop_back();
                cout<<n<<" ";
            } else
                return temp;

            if(n!=INT_MIN){
                rightc = new TreeNode(n);
                parent->right = rightc;
                head.push(rightc);
            }
            cout<<endl;
        }
        return temp;
        // return NULL;
    }
};
