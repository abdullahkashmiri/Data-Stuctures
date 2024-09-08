//
//#include<iostream>
//using namespace std;
//
//template<class T>
//class Node//class node
//{
//public:
//	T data;
//	Node <T>* next;
//	Node()//default constructor
//	{
//		data = 0;
//		next = NULL;
//	}
//	Node(T d)//overloaded constructor
//	{
//		data = d;
//		next = NULL;
//	}
//};
//template<class T>
//class SortedSet//linked list class
//{
//private:
//	Node <T>* head;
//	Node <T>* tail;
//public:
//	SortedSet()//default constructor
//	{
//		tail = new Node<T>;
//		head = tail;
//	}
//	SortedSet(Node<T>* h, Node<T>* t)//overloaded constructor
//	{
//		head = h;
//		tail = t;
//	}
//	void insert(T const dat)//insert function
//	{
//		Node<T>* newnode = new Node<T>(dat);
//		if (head == tail)//if no node then place at start
//		{
//			newnode->next = tail;
//			head = newnode;
//			return;
//		}
//		else
//		{
//			Node <T>* current = head;
//			if (current->data > newnode->data)//find its location according to data
//			{
//			newnode->next = current;
//			head = newnode;
//			return;
//			}
//			Node <T>* previous = current;
//			while (current->next != tail && current->data < newnode->data)
//			{
//				previous = current;
//				current = current->next;
//			}
//			if (current->data == newnode->data)//if data already present then skip
//			{
//				return;
//			}
//			else if (current->data > newnode->data && previous->data < newnode->data)//else case for placing data
//			{
//				newnode->next = current;
//				previous->next = newnode;
//			}
//			else//if no small element found the place at last
//			{
//				newnode->next = tail;
//				current->next = newnode;
//			}
//		}
//	}
//	void deleteindex(int const index)//delete a node function
//	{
//		Node <T>* current = head;
//		if (current == tail)// for empty linked list
//		{
//			cout << "Array is empty" << endl;
//			return;
//		}
//		int i = 0;
//		Node <T>* previous = current;
//		while (current->next != tail && i < index)//move until index is reached
//		{
//			previous = current;
//			current = current->next;
//			i++;
//		}
//		if (i == 0)//if zero index is given
//		{
//			head = current->next;
//			delete current;
//			return;
//		}
//		else if (i == index )//for required index
//		{
//			previous->next = current->next;
//			delete current;
//		}
//		else//index not found
//		{
//			cout << "Index : " <<index<<" Does not exist " << endl;
//			return;
//		}
//		cout << "SuccessFully Deleted entered Index : " << index << endl;
//	}
//	void print() const//print function
//	{
//		Node <T>* current = head;
//		if (current == tail)//for empty list
//		{
//			cout << "List is Empty" << endl;
//		}
//		else
//		{
//			cout << "Linked List is : ";
//			while (current != tail)//move till list is not reached to end
//			{
//				cout << current->data ;
//              if (current->next != tail)
//              cout<<",";
//				current = current->next;
//			}
//			cout << endl;
//		}
//		
//	}
//	void Union(SortedSet <T> const& otherSet)//union function
//	{
//		Node <T>* current = otherSet.head;//current pointer for set b
//		if (current == tail)// if set b is empty
//		{
//			return;
//		}
//		while (current != otherSet.tail)//insert data till set b is equal to null
//		{
//			insert(current->data);
//			current = current->next;
//		}
//	}
//	~SortedSet()//destructor
//	{
//		Node <T>* current = head;
//		Node <T>* next = current;
//		while (current != NULL)
//		{
//			next = current->next;
//			delete current;
//			current = next;
//		}
//		cout << "Destructor over here!" << endl;
//	}
//
//};
//int main()
//{
//	int option = 0, data, end = 0, no = 0;
//	SortedSet<int> ss, s1, s2;
//
//	cout << "How many Elements you want to insert : ";
//	cin >> no;
//	for (int i = 0; i < no; i++)
//	{
//		cout << "Enter data You want to insert : ";
//		cin >> data;
//		ss.insert(data);
//	}
//	ss.print();
//	cout << "How many indexes you want to delete : ";
//	cin >> no;
//	for (int i = 0; i < no; i++)
//	{
//		cout << "Enter index You want to delete : ";
//		cin >> data;
//		ss.deleteindex(data);
//	}
//	ss.print();
//	cout << "How many Elements you want to insert in SET A : ";
//	cin >> no;
//	for (int i = 0; i < no; i++)
//	{
//		cout << "Enter data You want to insert : ";
//		cin >> data;
//		s1.insert(data);
//	}
//	s1.print();
//	cout << "How many Elements you want to insert in SET B : ";
//	cin >> no;
//	for (int i = 0; i < no; i++)
//	{
//		cout << "Enter data You want to insert : ";
//		cin >> data;
//		s2.insert(data);
//	}
//	s2.print();
//	cout << "--------Union------" << endl;
//	s1.Union(s2);
//	s1.print();
//	return 0;
//}