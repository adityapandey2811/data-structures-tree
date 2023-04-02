//New Method
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p && q || !q && p || p->val != q->val) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

//Old Method
#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int structureMatchCheck(bt *root1, bt *root2){
    if(root1 == NULL && root2 == NULL)
        return 1;
    if(root1 != NULL && root2 != NULL){
        return (root1->data == root2->data && 
        structureMatchCheck(root1->left,root2->left) && 
        structureMatchCheck(root1->right,root2->right));
    }
    return 0;
}
int main(){
    bt *root1 = constructbt(),*root2 = constructbt();
    int n = structureMatchCheck(root1,root2);
    printf("%d\n",n);
    return 0;
}
