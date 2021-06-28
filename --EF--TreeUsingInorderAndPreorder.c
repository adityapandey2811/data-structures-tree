#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"btl.h"
int search(char in[], int start, int end, char toFind){
    while(start <= end){
        if(in[start] == toFind)
            return start;
        start++;
    }
    return -1;
}
bt *constructUsingInAndPre(char in[], char pr[], int inIndexStart, int inIndexEnd){
    int inIndexPos;
    static int prIndex = 0;
    bt* newNode = NULL;
    if(inIndexStart>inIndexEnd)
        return NULL;
    inIndexPos = search(in,inIndexStart,inIndexEnd,pr[prIndex]);
    newNode = (bt*)malloc(sizeof(bt));
    newNode->val = pr[prIndex++];
    newNode->left = newNode->right = NULL;
    if(inIndexEnd == inIndexStart)
        return newNode;
    newNode->left = constructUsingInAndPre(in,pr,inIndexStart,inIndexPos-1);
    newNode->right = constructUsingInAndPre(in,pr,inIndexPos+1,inIndexEnd);
    return newNode;
}
int main(){
    char in[20], pr[20];
    bt *root = NULL;
    printf("Inorder: ");
    scanf("%s",in);
    printf("Preorder: ");
    scanf("%s",pr);
    root = constructUsingInAndPre(in,pr,0,8);//use length of array instead of 8
    printf("Preorder: ");
    preorderc(root);
    printf("\nPostorder: ");
    postorderc(root);
    printf("\nInorder: ");
    inorderc(root);
    return 0;
}