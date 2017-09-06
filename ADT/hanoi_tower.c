#include<stdio.h>

void hanoi(int n, char f, char a, char t){
	if(n>0){
		hanoi(n-1, f, t, a);
		printf("Moving from %c to %c\n",f,t);
		hanoi(n-1, a, f, t);
	}
}

int main(){
	int n;
	char f='1', a='2', t='3';
	printf("n: ");
	scanf("%d",&n);
	hanoi(n,f,a,t);
	return 0;
}
