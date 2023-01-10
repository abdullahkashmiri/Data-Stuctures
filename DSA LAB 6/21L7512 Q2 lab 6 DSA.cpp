//////
//////Task 2:
//////Given a Queue of integers(Based on Linked List).The task is to check if the elements in the queue
//////are consecutive triples after every ‘k’ element.The queue will not be change after calling this
//////function.
//////Example :
//////
//////	Input : 1 2 3 5 7 11 12 13 k = 2
//////		Output : Yes
//////			 Input : 1 2 3 4 5 12 14 15 k = 2
//////				 Output : No
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
//			front = newnode;
//		}
//		else
//		{
//			rear->next = newnode;
//			rear = rear->next;
//		}
//		size++;
//	}
//	void deQueue(T &data)
//	{
//		if (!isEmpty())
//		{
//
//			data = front->data;
//			Node<T>*temp;
//			temp = front;
//			front = front->next;
//			delete temp;
//			size--;
//		}
//		else
//			data = NULL;
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
//		if (!isEmpty() && front)
//			return front->data;
//		return NULL;
//	}
//	T Rear()
//	{
//		if (!isEmpty() && rear)
//			return rear->data;
//		return NULL;
//	}
//	void Print()
//	{
//		Node<T>*current = front;
//		cout << "Queue is : ";
//		while (current)
//		{
//			cout << current->data << ",";
//			current = current->next;
//		}
//		cout << endl;
//	}
//	bool consecutiveTriplets(int k)
//	{
//		bool flag = true;
//		Queue<T> tq;
//		T val;
//		while (front&&!isEmpty())
//		{
//			for (int i = 0; i < 2 && front; i++)
//			{
//				deQueue(val);
//				tq.enQueue(val);
//				if ((tq.Rear()+1) !=( Front() ))
//				{
//					flag = false;
//				}
//			}
//			for (int i = 0; i <= k && front; i++)
//			{
//				deQueue(val);
//				tq.enQueue(val);
//			}
//		}
//		isEmpty();
//		while (!(tq.isEmpty()))
//		{
//			tq.deQueue(val);
//			enQueue(val);
//		}
//		cout << "consecutive triplets : ";
//
//		return flag;
//	}
//};
//
//int main()
//{
//	Queue<int> q;
//	int val;
//	cout << "Size : " << q.Size() << endl;
//
//	/*q.enQueue(1);
//	q.enQueue(2);
//	q.enQueue(3);
//	q.enQueue(5);
//	q.enQueue(7);
//	q.enQueue(11);
//	q.enQueue(12);
//	q.enQueue(13);*/
//
//	/*q.enQueue(1);
//	q.enQueue(2);
//	q.enQueue(3);
//	q.enQueue(4);
//	q.enQueue(5);
//	q.enQueue(12);
//	q.enQueue(14);
//	q.enQueue(15);*/
//
//
//
//	q.Print();
//	if (q.consecutiveTriplets(2)&&!q.isEmpty())
//		cout << "yes" << endl;
//	else cout << "no" << endl;
//	cout << "Size : " << q.Size() << endl;
//
//	q.Print();
//
//	system("pause");
//	return 0;
//}