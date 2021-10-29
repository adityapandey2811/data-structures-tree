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




//Same Technique little update

#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int lca(bt *root, int a, int b, int *res, int *init){
    int l, r;
    if(root == NULL)
        return 0;
    l = lca(root->left,a,b,res,init);
    r = lca(root->right,a,b,res,init);
    if(root->data == a){
        *init = *init + 1;
        return 1;
    }
    if(root->data == b){
        *init = *init + 1;
        return 1;
    }
    if(l == 1 && r == 1){
        *res = root->data;
        *init = 0;
        return 0;
    }
    if((l == 1 || r == 1) && *init == 2){
        *res = root->data;
        *init = 0;
        return 0;
    }
    if(l == 1 || r == 1)
        return 1;
    return 0;
}
int main(){
    int res = 0, init = 0;
    bt *root = constructbt();
    inorder(root);
    printf("\n");
    lca(root, 6, 9, &res, &init);
    printf("LCA: %d\n",res);
    return 0;
}
