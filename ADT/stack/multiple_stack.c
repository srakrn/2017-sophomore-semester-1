#include<stdio.h>

#define MAX_STACK 20
typedef struct{
	int Top;
	int StackItem[MAX_STACK];
} STACK;

void InitialiseStack(STACK *Stack){
	for(int i=0; i<MAX_STACK; i++){
		Stack -> StackItem[i] = 0;
	}
	Stack -> Top = 0;
}

int IsEmptyStack(STACK *Stack){
	return Stack -> Top == 0;
}
int IsFullStack(STACK *Stack){
	return Stack -> Top == MAX_STACK;
}
int PushStack(STACK *Stack, int Value){
	if(Stack -> Top > MAX_STACK){
		printf("Stack overflow.\n");
		return 0;
	}
	else{
		Stack -> StackItem[Stack -> Top] = Value;
		(Stack -> Top)++;
		return 1;
	}
}
int PopStack(STACK *Stack, int *Value){
	if(Stack -> Top <= 0){
		printf("Stack underflow.");
		*Value = 0;
		return 0;
	}
	else{
		(Stack -> Top)--;
		*Value = Stack -> StackItem[Stack-> Top];
		return 1;
	}
}
int main(){
	// Here we show the method of stack initialisation
	STACK myStack;
	InitialiseStack(&myStack);
	return 0;
}
