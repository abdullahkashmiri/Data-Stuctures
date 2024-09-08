//#include<iostream>
//using namespace std;
//
//template<class T>
//class Node  //Node class
//{
//public:
//	T data;
//	Node <T>* next;
//	Node()  //Default Constructor
//	{
//		data = 0;
//		next = NULL;
//	}
//	Node(T d)//OverLoaded Constructor
//	{
//		data = d;
//		next = NULL;
//	}
//};
//template<class T>
//class SortedSet//Linked List class
//{
//private:
//	Node <T>* head;
//	Node <T>* tail;
//public:
//	SortedSet()//Default Constructor
//	{
//		tail = new Node<T>;
//		head = tail;
//	}
//	SortedSet(Node<T>* h, Node<T>* t)  //OverLoaded Constuctor
//	{
//		head = h;
//		tail = t;
//	}
//	void insert(T const dat)//Insert Function
//	{
//		Node<T>* newnode = new Node<T>(dat);//new node
//		if (head == tail)//if empty the insert at start
//		{
//			newnode->next = tail;
//			head = newnode;
//			return;
//		}
//		else
//		{
//			Node <T>* current = head; //current pointer 
//			if (current->data > newnode->data)
//			{
//				newnode->next = current;
//				head = newnode;
//				return;
//			}
//			Node <T>* previous = current;
//			while (current->next != tail && current->data < newnode->data)
//			{
//				previous = current;
//				current = current->next;
//			}
//			if (current->data == newnode->data)
//			{
//				return;
//			}
//			else if (current->data > newnode->data && previous->data < newnode->data)
//			{
//				newnode->next = current;
//				previous->next = newnode;
//			}
//			else
//			{
//				newnode->next = tail;
//				current->next = newnode;
//			}
//		}
//	}
//	void print() const //print function
//	{
//		Node <T>* current = head;
//		if (current == tail) //list is empty
//		{
//			cout << "List is Empty" << endl;
//		}
//		else
//		{
//			cout << "Linked List is : ";
//			while (current != tail) //run until tail is reached
//			{
//				cout << current->data;
//				if (current->next != tail) //dont print -> after last data
//					cout << "->";
//				current = current->next;
//			}
//			cout << endl;
//		}
//
//	}
//	void reverseList() // Reverse function
//	{
//		if (head == tail || head->next == tail)//dont reverse if no or one element
//		{
//			return;
//		}
//		Node <T>* current = head;
//		Node <T>* previous = tail; // previous pointed to tail
//		Node <T>* next = NULL;
//		while (current != tail) //reverse algorithm
//		{
//			next = current->next;
//			current->next = previous;
//			previous = current;
//			current = next;
//		}
//		head = previous;// head pointed to last node
//		cout << "Reversed Successfully" << endl;
//	}
//	~SortedSet()//Destructor
//	{
//		Node <T>* current = head;
//		Node <T>* next = current;
//		while (current != NULL) //Run till last node is reached
//		{
//			next = current->next; //move next to current next
//			delete current; //delete current
//			current = next; //current equal to next
//		}
//		cout << "Destructor over here!" << endl;
//	}
//};
//int main()
//{
//	SortedSet<int> ss;
//	int no = 0, data = 0;
//	cout << "How many Elements you want to insert : ";
//	cin >> no;
//	for (int i = 0; i < no; i++)
//	{
//		cout << "Enter data You want to insert : ";
//		cin >> data;
//		ss.insert(data);
//
//	}
//	ss.print();
//	ss.reverseList();
//	ss.print();
//	cout << "--------------------------------------------------------------------\n";
//	return 0;
//}