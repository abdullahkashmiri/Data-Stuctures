//
///*
//Question 1
//Implement a template-based stack using a singly linked list. The required member methods are:
//1. int size(): returns the count of total element stored in the stack.
//2. bool isEmpty(): returns true if the stack is empty else false.
//3. bool top(T&amp;): returns, but does not delete, the topmost element from the stack via the parameter
//passed by reference. It returns false via a return statement if there is no element in the stack, else
//it returns true and assigns the top most element to the parameter passed by reference.
//4. void pop(): deletes the top most element from the stack. If there is no element, return some error.
//5. push(T const&amp; e): pushes the element “e” on top of the stack.
//*/
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
//	Stack<int> s;
//	int val;
//	s.Print();
//	
//	s.push(2);
//	s.push(4);
//	s.push(10);
//	s.Print();
//
//	s.pop(val);
//	cout << "POPED : " << val << endl;
//	val = -1;
//	s.pop(val);
//	cout << "POPED : " << val << endl;
//	s.top(val);
//	cout << "TOP val : " << val << endl;
//	val = -1;
//	s.pop(val);
//	cout << "POPED : " << val << endl;
//	val = -1;
//	s.pop(val);
//	val = -1;
//	cout << "POPED : " << val << endl;
//	s.Print();
//	
//	system("pause");
//	return 0;
//}