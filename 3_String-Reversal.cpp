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

int main() {

	int size;
	char string[30];

	cout << "Enter Stack size" << endl;
	cin >> size;
	initStack(size);

	cout << "Enter string to reverse" << endl;
	cin >> string;

	for (int i = 0; i <= strlen(string); i++) {
		push(string[i]);
	}
	printStack();
}
