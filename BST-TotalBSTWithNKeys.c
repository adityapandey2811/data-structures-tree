//Structurally Unique BST with n keys using CATALAN NUMBER [2nCn/n+1]
#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int factorial(int n){
	if(n==0)
		return 1;
	return n*factorial(n-1);
}
int main(){
	int n;
	scanf("%d",&n);
	n = factorial(2*n)/(factorial(n)*factorial(n+1));
	printf("%d\n",n);
	return 0;
}
