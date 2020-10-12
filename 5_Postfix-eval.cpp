#include<iostream>
using namespace std;
//Global
char s[100], MaxSize, tos;

//1
void initStack(int size) {
	//stack initialization
	MaxSize = size;
	tos = -1;
}
//2
void push(char c) {
	tos++;
	s[tos] = c;		//add data in stack
}
//3
int isFull() {
	if (tos == MaxSize - 1)
		return 1;		// before pushing, wheher the stack is Full
	else
		return 0;
	//4
}char pop() {
	char temp;
	temp = s[tos];		// removes data...LIFO
	tos--;
	return temp;
}
//5
int isEmpty() {
	if (tos == -1)
		return 1;		// before poping, need to check whether the stack is empty
	else
		return 0;
}
//6
int atTop() {
	return(s[tos]);		//does not remove element, just returns the top element
}
//7
void printStack() {
	for (int i = tos; i > -1; i--) {
		cout << s[i];	//LIFO
	}
}

int precedence(char c) {
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	else
		return 0;

}

int main() {

	char post[100], ch;
	int op1=0, op2=0, value=0;
	cout << "Enter postfix" << endl;
	cin >> post;
	initStack(strlen(post));
	

	for (int i = 0; i<strlen(post); i++) {
		char c;
		ch = post[i];
		
		switch (ch) {

		case'+': case '-': case'/': case'*': 
			op1= pop()- '0';
			op2= pop() - '0';

			if (ch == '+') {
				value = op2 + op1;
			}
			if (ch == '-') {
				value = op2 - op1;
			}
			if (ch == '/') {
				value = op2 / op1;
			}
			if (ch == '*') {
				value = op2 * op1;
			}
			c = value + '0';
			push(c);
			break;
		default: 
			push(ch);
			break;
		}
	}
	cout << (value = pop() - '0');
	
	

}