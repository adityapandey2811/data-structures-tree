//My new way
int diameter(TreeNode *root, int *res){
    int l,r, ans;
    if(!root) return 0;
    else{
        l = diameter(root->left,res);
        r = diameter(root->right,res);
    }
    *res = max(l+r+1, *res);
    if(l>r){
        return l+1;
    } else {
        return r+1;
    }
}

//My old way
#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int max(int l, int r){
    if(l>=r)
        return l;
    else
        return r;
}
int diameter(bt *root, int *res){
    if(root == NULL)
        return 0;
        
    int l = diameter(root->left, res);
    int r = diameter(root->right, res);

    int temp = max(l,r) + 1;
    int ans = 1+l+r;
    *res = max(*res,ans);

    return temp;
}
int main(){
    int res = INT_MIN;
    bt *root = constructbt();
    diameter(root,&res);
    printf("%d\n",res);
    return 0;
}
