///*
//Question 2
//Remove all triple adjacent characters from a string using Stack.
//Input: azxxxy
//Output: azy
//*/
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
//	
//public:
//	int size;
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
//	/*bool RemoveTripleAdjacent()
//	{
//		Node<T>*next = head.next; 
//		if (!next||!next->next||!next->next->next)
//		{
//			cout << "aa\n";
//			return false;
//		}
//		cout << "bb\n";
//
//		Node<T>*previous = &head;
//		Node<T>*current = next;
//		next = current->next;
//		while (next->next != NULL)
//		{
//			cout << previous->next->data << endl;
//			cout << current->next->data << endl;
//			cout << next->next->data << endl << endl;
//			if ((previous->next->data) == (current->next->data) && (next->next->data) == (current->next->data))
//			{
//				cout << previous->next->data << endl;
//				cout << current->next->data << endl;
//				cout << next->next->data << endl << endl;
//				previous->next = next->next;
//
//				delete next;
//				delete current;
//				if (previous != &head)
//				{
//					delete previous;
//				}
//			}
//			previous = current;
//			current = next;
//			next = next->next;
//		}
//
//		return true;
//	}*/
//
//	Stack RemoveTripleAdjacent(Stack s)//O(n)
//	{
//		T v1, v2, v3;
//		if (s.size<3)
//		{
//			return s;
//		}
//		if (!s.isEmpty() && s.size > 3)
//		{
//			
//			s.pop(val);
//			v1 = val;
//			s.pop(val);
//			v2 = val;
//			s.pop(val);
//			v3 = val;
//		}
//		while (!s.isEmpty() )
//		{
//			if (v1 == v2 && v2== v3)
//			{
//				if (!s.isEmpty())
//				s.pop(val);
//				v1 = val;
//				val = NULL;
//				if (!s.isEmpty())
//				s.pop(val);
//				v2 = val;
//				val = NULL;
//				if (!s.isEmpty())
//				s.pop(val);
//				v3 = val;
//				val = NULL;
//			}
//			if (v1 != v2)
//			{
//				push(v1);
//			}
//			v1 = v2;
//			v2 = v3;
//			if (!s.isEmpty())
//			s.pop(val);
//			v3 = val;
//		}
//		if (v1 != 'x')
//		push(v1);
//		while (!s.isEmpty())
//		{
//			s.pop(val);
//			v1 = val;
//			push(val);
//		}
//		while (!isEmpty())
//		{
//			pop(val);
//			s.push(val);
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
//	Stack<char> s, ss;
//	char val;
//	s.Print();
//	
//	
//	s.push('a');
//	s.push('z');
//	s.push('x');
//	s.push('x');
//	s.push('x');
//	s.push('y');
//	s.push('x');
//	s.push('x');
//	s.push('x');
//	
//	s.Print();
//	ss = ss.RemoveTripleAdjacent(s);
//	ss.Print();
//	//s.Print();
//
//	
//	system("pause");
//	return 0;
//}