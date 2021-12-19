//Structurally Unique BST with n keys using CATALAN NUMBER [2nCn/n+1] or (2n)!/((n+1)!*n!) and Dynamic Programming [ Cn = C0*Cn-1 + C1*Cn-2 + ...... + Cn-1*C0 ]
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
