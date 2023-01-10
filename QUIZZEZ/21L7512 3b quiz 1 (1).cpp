//
//#include<iostream>
//using namespace std;
//
//template<class T>
//class Node
//{
//public:
//	T data;
//	Node *next;
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
//template<class T>
//class LinkedList
//{
//	Node<T> head;
//public:
//	LinkedList()
//	{
//		head = NULL;
//	}
//	void insert(T val)
//	{
//		Node<T>*newnode = new Node<T>(val);
//		Node<T>*current = &head;
//		while (current->next != NULL)
//		{
//			current = current->next;
//		}
//		current->next = newnode;
//	}
//	void Print()
//	{
//		if (head.next == NULL)
//		{
//			cout << "Empty List" << endl;
//			return;
//		}
//		Node<T>*current = head.next;
//		cout << "Linked LIst is : ";
//		while (current!= NULL)
//		{
//			cout << current->data<<",";
//			current = current->next;
//		}
//		cout << endl;
//	}
//
//	LinkedList Addition(LinkedList<T> l1, LinkedList <T>l2)
//	{
//		Node<T>*l11 = &l1.head;
//		Node<T>*l22 = &l2.head;
//	
//		l11 = l11->next;
//		l22 = l22->next;
//		T add;
//		int count = 0;
//		while (l11 != NULL || l22 != NULL)
//		{
//			count = 0;
//			if (l11->next != NULL && l22->next != NULL)
//			{
//				add = l11->data + l22->data;
//				//add += count;
//				while (add >= 10)
//				{
//					add = add - 10;
//					count++;
//				}
//			}
//			else if (l11->next != NULL && l22->next == NULL)
//			{
//				add = l11->data;
//			}
//			else if (l11->next == NULL && l22->next != NULL)
//			{
//				add = l22->data;
//			}
//
//			insert(add);
//			add = 0;
//			add += count;
//			l11 = l11->next;
//			l22=l22->next;
//		}
//
//		return *this;
//	}
//	~LinkedList()
//	{
//		if (head.next == NULL)
//		{
//			return;
//		}
//		Node<T>*previous = &head;
//		Node<T>*current = head.next;
//		while (!current)
//		{
//			previous = current;
//			current = current->next;
//			delete previous;
//		}
//	}
//
//};
//
//
//int main()
//{
//	LinkedList<int> l1, l2, r;
//	l1.Print();
//	l2.Print();
//
//	l1.insert(2);
//	l1.insert(4);
//	l1.insert(3);
//
//	l2.insert(5);
//	l2.insert(6);
//	l2.insert(4);
//
//	l1.Print();
//	l2.Print();
//
//	r.Addition(l1, l2);
//	r.Print();
//
//	system("pause");
//	return 0;
//}