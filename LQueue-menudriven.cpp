#include<iostream>
using namespace std;

int Q[100], rear, front, maxSize;

void createQueue(int size) {
	maxSize = size;
	front = 0;
	rear = -1;		//No data in queue yet
	cout << "Queue created" << endl;
}

void enQueue(int e) {
	rear++;
	Q[rear] = e;
}

int deQueue() {

	int temp = Q[front];
	front++;
	return temp;
}

int isFull() {
	if (rear == maxSize-1)
		return 1;
	else
		return 0;
}

int isEmpty() {
	if (front > rear)
		return 1;
	else
		return 0;
}

void printQueue() {
	for (int i = front; i <= rear; i++) {
		cout << Q[i]<< " ";
	}
	
}
int main() {

	int size, choice,e;
	cout << "Enter Queue size";
	cin >> size;
	createQueue(size);

	do {
		cout << "\n 1. enQueue \n 2. deQueue \n 3. printQueue \n 0. Exit\n"<<endl;
		cin >> choice;
		switch (choice) {
		case 1: 
			if (isFull() == 1) {
				cout << "Queue is full" << endl;
			}
			else {
				cout << "Enter data";
				cin >> e;
				enQueue(e);
			}
			break;

		case 2:
			if (isEmpty() == 1) {
				cout << "Queue is Empty";
			}
			else {
				e = deQueue();
				cout << "deleting\t"<< e;

			}
			break;
		case 3:
			if (isEmpty() == 1) {
				cout << "Queue is Empty";
			}
			else
				printQueue();
			break;
		case 0:
			cout << "exiting";
			break;
		default: cout << "Invalid";
			break;
		}
	
	} while (choice!=0);

} 