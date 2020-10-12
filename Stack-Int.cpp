#include<iostream>
using namespace std;
//Global
int s[100], MaxSize, tos;

//1
void initStack(int size) {
	//stack initialization
	MaxSize = size;
	tos = -1;
}
//2
void push(int e) {
	tos++;		
	s[tos] = e;		//add data in stack
}
//3
int isFull() {
	if (tos == MaxSize - 1)
		return 1;		// before pushing, wheher the stack is Full
	else
		return 0;
//4
}int pop() {
	int temp;
	temp = s[tos];		// removes data...LIFO
	tos--;
	return temp;
}
//5
int isEmpty() {
	if (tos == -1)
		return 1;		// before pooping, need to check whether the stack is empty
	else
		return 0;
}
//6
int atTop() {
	return(s[tos]);		//does not remove element, just returns the top element
}
//7
void printStack() {
	for (int i = 0; i > -1; i--) {
		cout << s[i] << endl;		//LIFO
	}
}

