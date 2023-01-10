////Question 3: (‘Undo’ Stack)[10 marks]
////Create a class called UndoStack.This stack is intended to be used for the undo operation in another application.It
////should have the property that it remembers at most the last 100 elements pushed into it.So, for example, if there
////were 101 push operations it would “forget” the oldest of these and if a pop happens the 2nd pushed element will
////be popped, etc.Write complete C++ code for this class.
//
//#include<iostream>
//using namespace std;
//
//template<class T>
//class Node//template class Node
//{
//public://Data members
//	T data;
//	Node<T>* next;
//	Node<T>* previous;
//	Node()//default constructor O(1)
//	{
//		next = NULL;
//		previous = NULL;
//		data = NULL;
//	}
//	Node(T d)//overloaded constructor  O(1)
//	{
//		next = NULL;
//		previous = NULL;
//		data = d;
//	}
//};
//template<class T>
//class Undo_Stack//template class undo stack
//{
//private://data members
//	Node<T>* head;
//	Node<T>* tail;
//	int count;
//public:
//	Undo_Stack()//default constructor  O(1)
//	{
//		head = NULL;
//		tail = NULL;
//		count = 0;
//	}
//	Undo_Stack(Node<T>* h, int c, Node<T>* t)//overloaded constructor  O(1)
//	{
//		head = h;
//		tail = t;
//		count = c;
//	}
//	void push(T data)//insertion in stack  O(1)
//	{
//		isFULL();//is full function
//		Node<T>* newnode = new  Node<T>(data);
//		if (head == NULL)//if stack is empty
//		{
//			head = newnode;
//			tail = newnode;
//		}
//		else
//		{
//			newnode->previous = tail;
//			tail->next = newnode;
//			tail = newnode;
//		}
//		count++;//size count
//	}
//	void pop(T& data)//pop function  O(1)
//	{
//		Node<T>* temp = tail;//poping at tail
//		data = temp->data;
//		tail = temp->previous;
//		delete temp;//deleting node temp
//		count--;
//	}
//	bool isEmpty()//is empty function  O(1)
//	{
//		if (tail == NULL)
//		{
//			return true;
//		}
//		return false;
//	}
//	void isFULL()//is full function  O(1)
//	{
//		if (count == 10)//size = maxsize
//		{
//			Node<T>* temp = head;//deleting node entered first
//			head = head->next;
//			head->previous = NULL;
//			delete temp;
//			count--;//decreasing size
//		}
//	}
//};
//int main()
//{
//	char data = 0;
//	Undo_Stack<char> us;
//	cout << "Enter data into single alphabets into Stack and press DOT (.) for termination " << endl;
//	cout << "Enter single char once" << endl;
//	while (data != '.')
//	{
//		cin >> data;
//		if(data!='.')
//		us.push(data);
//	}
//	cout << "DATA ENTERED is : ";
//	while(!us.isEmpty())
//	{
//		us.pop(data);
//		cout << data;
//	}
//	return 0;
//}