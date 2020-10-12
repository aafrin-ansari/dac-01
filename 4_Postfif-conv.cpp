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
	int p = 0;
	char postfix[100], infix[100], ch;

	cout << "Enter infix" << endl;
	cin >> infix; 
		initStack(strlen(infix));	//Stack Initialization

	for (int i = 0; i < strlen(infix); i++) {

		ch = infix[i];
		switch (ch) {

		case'(':
			push(ch);
			break;

		case')':
			while (s[tos] != '(' || isEmpty() == 1) {
				postfix[p] = pop();
				p++;
			}
			ch = pop();
			break;

		case'+': case'-': case'*': case'/':
			while ((precedence(ch) <= precedence(s[tos])) && (isEmpty() != 1)) {
				postfix[p] = pop();
				p++;
			}
			push(ch);
			break;
		default:
			postfix[p] = ch;
			p++;
			break;
		}
	}
	while (isEmpty() != 1) {
		postfix[p] = pop();
		p++;
	}

	cout << postfix;
}