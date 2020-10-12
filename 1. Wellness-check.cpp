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
	initStack(40);
	
	cout << "Stack Initalized\n";
	char braces[20];
	cout << "Enter data << endl;
	cin >> braces;
	

	for (int i = 0; i<=strlen(braces); i++) {

		if (braces[i] == '(' || braces[i] == '{' || braces[i] == '[' ) {
			push(braces[i]); 
		}

		if (braces[i] == ')' || braces[i] == '}' || braces[i] == ']') {
			pop();
		}
	}
	
	//cout << isEmpty() << endl;;
	if (isEmpty() == 1) {
		cout << "Balanced!" << endl;
	}
	else {
		cout << "Unexpected Error!" << endl;
	}

}
