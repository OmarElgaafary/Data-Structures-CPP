#include <iostream>

int queue[10];
int front = -1;
int rear = -1;

void Enqueue(int x)
{
	if (rear == -1 && front == -1)
	{
		++front;
		++rear;
		queue[rear] = x;
	}
	else if ((rear + 1) % 10 == front)
		return;
	else
	{
		rear = (rear + 1) % 10;
		queue[rear] = x;
	}
}

void Dequeue()
{
	if (rear == -1 && front == -1)
		return;
	else if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		queue[front] = 0;
		front = (front + 1) % 10;
	}
}


int main()
{
	Enqueue(3);
	Enqueue(5);
	Enqueue(7);
	Enqueue(9);
	Enqueue(11);
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();

	for (int i = 0; i < 10; i++) std::cout << queue[i] << ", ";
}
