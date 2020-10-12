#include<iostream>
using namespace std;

int Q[100], rear, front, maxSize;

void createQueue(int size) {
	maxSize = size;
	front = 0;
	rear = -1;		//No data in queue yet
	cout << "Queue created is of size" + size << endl;
}

void enQueue(int e) {
	rear++;
	Q[rear] = e;
}

int deQueue() {

	int temp; temp= Q[front];
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
		cout << Q[i] << endl;
	}
}

