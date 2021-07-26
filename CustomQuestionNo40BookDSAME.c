#include<stdio.h>
#include<stdlib.h>
int findDepth(int tree[], int n){
    int i,j,currentDepth = 0,maxDepth = INT_MIN;
    for(i=0;i<n;i++){
        currentDepth = 0;
        j = i;
        while(tree[j] != -1){
            currentDepth++;
            j = tree[j];
        }
        if(currentDepth > maxDepth)
            maxDepth = currentDepth;
    }
    return maxDepth;
}
int main(){
    int tree[9] = {-1,0,1,6,6,0,0,2,7},h,n = sizeof(tree)/sizeof(int);
    h = findDepth(tree, n);
    printf("%d\n",h);
    return 0;
}