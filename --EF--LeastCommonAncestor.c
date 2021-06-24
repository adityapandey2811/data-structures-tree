#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int lca(bt *root, int a, int b, int *res, int *init){
    int l,r;
    if(root == NULL)
        return 0;
    l = lca(root->left,a,b,res,init);
    r = lca(root->right,a,b,res,init);
    if(l == 1 && r == 1)
        *res = root->data;
    if(root->data == a || root->data == b){
        *init+=1;
        if((*init == 2) && (l == 1 || r == 1)){
            *res = root->data;
            return 0;
        }
        return 1;
    }
    if(l == 1 || r == 1)
        return 1;
}
int main(){
    bt *root = constructbt();
    int res = 0, init = 0;
    int n = lca(root,2,2,&res,&init);
    printf("%d\n",res);
    return 0;
}