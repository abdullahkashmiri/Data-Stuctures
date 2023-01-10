//#include<iostream>
//using namespace std;
//
//template<class T>//template class Node
//class Node
//{
//public://data members
//	T data;
//	Node <T>* next;
//	Node <T>* prev;
//	Node()//Default Constructor   O(1)
//	{
//		data = NULL;
//		next = NULL;
//		prev = NULL;
//	}
//	Node(T da)//Overloaded Constructor   O(1)
//	{
//		data = da;
//		next = NULL;
//		prev = NULL;
//	}
//};
//
//template<class T>//Template class Linked List
//class LinkedList
//{
//private://data members
//	Node <T> head;
//	int size = 0;
//	int MaxSize = 5;
//	bool flag = true;
//public:
//	LinkedList()//Default Constructor   O(1)
//	{
//		head = NULL;
//	}
//	LinkedList(Node<T> h)//Overloaded Constructor   O(1)
//	{
//		head = h;
//	}
//	void push(T data)//Push Function
//	{
//		Node<T>* newnode = new Node<T>(data);
//		if (isEmpty())//insertion at head doubly linked list   O(1)
//		{
//			newnode->next = &head;
//			newnode->prev = &head;
//			head.next = newnode;
//			head.prev = newnode;
//			size++;
//			return;
//		}
//		if (flag)//insertion accoring to flag here at head   O(1)
//		{
//			Node<T>* temp = head.next;
//			temp->prev = newnode;
//			newnode->next = temp;
//			newnode->prev = &head;
//			head.next = newnode;
//			size++;
//		}
//		else if (!flag)//insertion accoring to flag here behind head   O(1)
//		{
//			Node<T>* temp = head.prev;
//			temp->next = newnode;
//			newnode->prev = temp;
//			newnode->next = &head;
//			head.prev = newnode;
//			size++;
//		}
//	}
//	void update_size()//update max size according to current size   O(1)
//	{
//		if (size == MaxSize)
//		{
//			MaxSize = MaxSize * 2;
//		}
//		else if ((size * 2) == MaxSize && MaxSize >= 5)
//		{
//			MaxSize = MaxSize / 2;
//		}
//	}
//	bool isFull()//checking if stack is full   O(1)
//	{
//		update_size();
//		return false;
//	}
//	bool isEmpty()//checking if stack is empty   O(1)
//	{
//		if (size == 0)
//		{
//			return true;
//		}
//		update_size();
//		return false;
//	}
//	T pop()//pop function   O(1)
//	{
//		if (!isEmpty())
//		{
//			if (flag)//if not flipped
//			{
//				T data;
//				Node<T>* previous = &head;
//				previous = previous->next;
//				Node<T>* next = previous->next;
//				next->prev = &head;
//				head.next = next;
//				data = previous->data;
//				delete previous;
//				size--;
//				return data;
//			}
//			if (!flag)// if flipped
//			{
//				T data;
//				Node<T>* previous = &head;
//				previous = previous->prev;
//				Node<T>* next = previous->prev;
//				next->next = &head;
//				head.prev = next;
//				data = previous->data;
//				delete previous;
//				size--;
//				return data;
//			}
//		}
//		return NULL;
//	}
//	void print()//print function   O(n)
//	{
//		cout << "Size : " << size << " MAX SIZE : " << MaxSize << endl;
//		if (size==0)
//		{
//			cout << "Empty List" << endl;
//			return;
//		}
//		Node<T>* current = &head;
//		cout << "LINKED LIST is : ";
//		while (current->next != &head)
//		{
//			cout << current->next->data << ",";
//			current = current->next;
//		}
//		cout << endl;
//	}
//	void Flip_Stack()//flip stack function   O(1)
//	{
//		if (!head.next)
//		{
//			cout << "Empty List Cannot Be Flipped." << endl;
//			return;
//		}
//		flag = !flag;
//		cout << "Fliped SuccessFully" << endl;
//	}
//};
//int main()
//{
//	LinkedList<int> l;
//	int option, data;
//	cout << "\t1->Push\t\t2->Pop\t\t3->Flip_Stack\t\t4->Print\t\t0->EXIT\n";
//	while (true)
//	{
//		cout << "Enter Desired Option : ";
//		cin >> option;
//		if (option == 1)
//		{
//			cout << "How many elements you want to Push : ";
//			cin >> option;
//			for (int i = 0; i < option; i++)
//			{
//				cout << "Enter Data : ";
//				cin >> data;
//				l.push(data);
//			}
//		}
//		else if (option == 2)
//		{
//			cout << "How many elements you want to Pop : ";
//			cin >> option;
//			cout << "Data is ";
//			for (int i = 0; i < option; i++)
//			{
//				cout << l.pop() << ",";
//			}
//			cout << endl;
//		}
//		else if (option == 3)
//		{
//			l.Flip_Stack();
//		}
//		else if (option == 4)
//		{
//			l.print();
//		}
//		else if (option == 0)
//		{
//			break;
//		}
//		else
//			cout << "Error Occured!! ->In-Valid Option Selected!!<-" << endl;
//	}
//	return 0;
//}
