///*
//Task 1:
//Implement a template-based queue using Linked List. The required member methods are:
//a) void enqueue(): Adds an element to queue
//b) void dequeue(): Removes an element from queue
//c) int size(): returns the count of total element stored in the stack.
//d) bool isEmpty(): returns true if the stack is empty else false.
//e) int front(): returns the element on Front of queue
//f) int rear(): return the element on Rear of queue
//*/
//
//
//#include<iostream>
//using namespace std;
//template<class T>
//class Node
//{
//public:
//	T data;
//	Node*next;
//	Node()
//	{
//		data = NULL;
//		next = NULL;
//	}
//	Node(T d)
//	{
//		data = d;
//		next = NULL;
//	}
//};
//
//template<class T>
//class Queue
//{
//private:
//	Node<T>* front;
//	Node <T> *rear;
//	int size;
//public:
//	Queue()
//	{
//		front = NULL;
//		rear = NULL;
//		size = 0;
//	}
//	void enQueue(T data)
//	{
//		Node<T>*newnode = new Node<T>(data);
//		if (rear == NULL)
//		{
//			rear = newnode;
//			front= newnode;
//		}
//		else
//		{
//			rear->next = newnode;
//			rear = rear->next;
//		}
//		size++;
//		cout << "pushed : " << data << endl;
//	}
//	void deQueue(T &data)
//	{
//		if (!isEmpty())
//		{
//	
//		data = front->data;
//		Node<T>*temp;
//		temp = front;
//		front = front->next;
//		delete temp;
//		size--;
//		
//		}
//		else
//		data = -1;
//	}
//	int Size()
//	{
//		return size;
//	}
//	bool isEmpty()
//	{
//		if (size == 0)
//		{
//			cout << "Empty List!!" << endl;
//			front = rear = NULL;
//			return true;
//		}
//		return false;
//	}
//	T Front()
//	{
//		if (!isEmpty()&&front)
//			return front->data;
//		return NULL;
//	}
//	T Rear()
//	{
//		if (!isEmpty()&&rear)
//			return rear->data;
//		return NULL;
//	}
//};
//
//int main()
//{
//	Queue<int> q;
//	int val;
//	cout << "Size : " << q.Size() << endl;
//
//	q.enQueue(15);
//	q.enQueue(3);
//	q.enQueue(25);
//	q.enQueue(12);
//	cout << "Size : " << q.Size() << endl;
//
//	q.deQueue(val);
//	cout << "deQueue : " << val << endl;
//	q.deQueue(val);
//	cout << "deQueue : " << val << endl;
//	cout << "Size : " << q.Size() << endl;
//	cout << "front : " << q.Front() << endl;
//	cout << "rear : " << q.Rear() << endl;
//	q.deQueue(val);
//	cout << "deQueue : " << val << endl;
//	q.deQueue(val);
//	cout << "deQueue : " << val << endl;
//	q.deQueue(val);
//	cout << "deQueue : " << val << endl;
//	q.deQueue(val);
//	cout << "deQueue : " << val << endl;
//
//	
//	system("pause");
//  	return 0;
//}