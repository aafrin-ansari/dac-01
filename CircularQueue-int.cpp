#include<iostream>
using namespace std;

int Q[100], rear, front, maxSize, counter;

void createQueue(int size) {
	maxSize = size;
	front = 0;
	rear = -1;
	counter = 0;
	cout << "Queue created" << endl;
}
void enQueue(int e) {
	rear = (rear + 1) % maxSize;
	counter++;
	Q[rear] = e;
}
int deQueue() {
	int temp = Q[front];
	counter--;
	front = (front + 1) % maxSize;
	return temp;
}
int isFull() {
	if (counter == maxSize)
		return 1;
	else
		return 0;
}
int isEmpty() {
	if (counter == 0)
		return 1;
	else
		return 0;
}
void printQueue() {
	int i, c = 0;
	i = front;
	while (c < counter) {
		cout << Q[i]<< " ";
		i = (i + 1) % maxSize;
		c++;
	}
}