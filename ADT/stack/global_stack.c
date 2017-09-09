#include<stdio.h>

#define MAX_STACK 10
int Stack[MAX_STACK];
int top = 0;

// Stack Initialise function.
// This should be called on code's initialise
void InitialiseStack(){
	for(int i=0; i<MAX_STACK; i++){
		Stack[i] = 0;
	}
	top = 0;
}

// Stack status function: IsEmpty() and IsFull()
// Does what its name said.
int StackIsEmpty(){
	return top == 0;
}
int StackIsFull(){
	return top == MAX_STACK;
}

// Push, Pop, and Peek.
// - Push adds a value to stack.
// - Pop pops out (remove) the value from the stack.
//   it also returns the popped value by reference.
// - Peek returns the latest value, but does not
//   remove it from the stack.
int PushStack(int v){
	if(StackIsFull()){
		printf("Stack overflow.");
		return 0;
	}
	else{
		Stack[top] = v;
		top++;
		return 1;
	}
}
int PopStack(int *v){
	if(StackIsEmpty()){
		printf("Stack underflow.");
		return 0;
		// Pass by value for return code
	}
	else{
		top--;
		*v = Stack[top];
		// Pass by reference for real stack value
		return 1;
	}
}
int PeekStack(int *v){
	if(StackIsEmpty()){
		printf("Stack underflow.");
		return 0;
		// Pass by value for return code
	}
	else{
		*v = Stack[top-1];
		// Pass by reference for real stack value
	}
}

// Nothing about the stack; just for demonstration.
void PrintStack(){
	for(int i=MAX_STACK-1; i>=0; i--){
		printf(" %d\t",Stack[i]);
		if(i==top){
			printf(" <- Top\n");
		}
		else{
			printf("\n");
		}
	}
}

int main(){
	return 0;
}
