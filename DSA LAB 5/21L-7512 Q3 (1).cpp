/////*
////
////Question 3
////Delete middle element of a stack
////Given a stack with push(), pop(), empty() operations, delete the middle of it without using any
////additional data structure.
////Input: Stack[] = [1, 2, 3, 4, 5]
////Output: Stack[] = [1, 2, 4, 5]
////Input: Stack[] = [1, 2, 3, 4, 5, 6]
////Output: Stack[] = [1, 2, 4, 5, 6]
////
////Note: You are required to find time complexity of every function mentioned above and mention in
////comments with the respective function.
////
////*/
////
//
//
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
//class Stack
//{
//	Node<T> head;
//	T val;
//	int size;
//public:
//	Stack()
//	{
//		head = NULL;
//		size = 0;
//		val = NULL;
//	}
//	void push(T val)//O(1)
//	{
//		Node<T>*newnode = new Node<T>(val);
//		newnode->next = head.next;
//		head.next = newnode;
//		size++;
//	}
//
//	bool isEmpty()//O(1)
//	{
//		if (!head.next)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	bool top(T & val)//O(1)
//	{
//		if (!isEmpty())
//		{
//			Node<T>*current = head.next;
//			val = current->data;
//			return true;
//		}
//		return false;
//	}
//
//	void pop(T & val)//O(1)
//	{
//		if (!isEmpty())
//		{
//			Node<T>*current = head.next;
//			val = current->data;
//			head.next = current->next;
//			delete current;
//			size--;
//			return;
//		}
//		cout << "Error !! Empty Stack" << endl;
//	}
//
//	void Print()//O(n)
//	{
//		cout << "SIZE : " << size << endl;
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
//	Stack DeleteMiddle(Stack& s)//O(n)
//	{
//		int a = 0;
//		while (!s.isEmpty())
//		{
//			s.pop(val);
//			push(val);
//			a++;
//		}
//		for (int i = 0; i < a; i++)
//		{
//			if (i != a / 2)
//			{
//				pop(val);
//				s.push(val);
//			}
//			else
//				pop(val);
//		}
//		return s;
//	}
//
//	~Stack()//O(n)
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
//	Stack<int> s,ss;
//	int val;
//	s.Print();
//	//
//	//s.push(1);
//	//s.push(2);
//	//s.push(3);
//	//s.push(4);
//	//s.push(5);
//	//s.push(6);
//
//
//	s.push(6);
//	s.push(5);
//	s.push(4);
//	s.push(3);
//	s.push(2);
//	s.push(1);
//
//	s.Print();
//
//	ss=ss.DeleteMiddle(s);
//
//	ss.Print();
//	
//	system("pause");
//	return 0;
//}