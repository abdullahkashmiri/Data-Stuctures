//#include<iostream>
//using namespace std;
//
//template<class T>
//class Node //Node class
//{
//public:
//	T data;
//	Node <T>* next;
//	Node() //Default Constructor
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
//	SortedSet(Node<T>* h, Node<T>* t) //OverLoaded Constuctor
//	{
//		head = h;
//		tail = t;
//	}
//	void insert(T const dat)//Insert Function
//	{
//		Node<T>* newnode = new Node<T>(dat);
//		if (head == tail)
//		{
//			newnode->next = tail;
//			head = newnode;
//			return;
//		}
//		else
//		{
//			Node <T>* current = head;
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
//	void deleteindex(int const index)//delete index function
//	{
//		Node <T>* current = head;
//		if (current == tail)// for empty array
//		{
//			cout << "Array is empty" << endl;
//			return;
//		}
//		int i = 0;
//		Node <T>* previous = current;
//
//		while (current->next != tail && i < index)
//		{
//			previous = current;
//			current = current->next;
//			i++;
//		}
//		if (i == 0)
//		{
//			head = current->next;
//			delete current;
//			return;
//		}
//		else if (i == index)
//		{
//			previous->next = current->next;
//			delete current;
//		}
//		else
//		{
//			cout << "Index : " << index << " Does not exist " << endl;
//		}
//	}
//	void print() const//print function
//	{
//		Node <T>* current = head;
//		if (current == tail)
//		{
//			cout << "List is Empty" << endl;
//		}
//		else
//		{
//			cout << "Linked List is : ";
//			while (current != tail)
//			{
//				cout << current->data; 
//				if (current->next != tail)
//					cout << "->";
//				current = current->next;
//			}
//			cout << endl;
//		}
//
//	}
//	void Union(SortedSet <T> const& otherSet)//union function
//	{
//		Node <T>* current = otherSet.head;
//		if (current == tail)
//		{
//			return;
//		}
//		while (current != otherSet.tail)
//		{
//			insert(current->data);
//			current = current->next;
//		}
//	}
//	void rotate()//rotate function
//	{
//		if (head == tail)
//		{
//			return;
//		}
//		Node <T>* start = head;
//		Node <T>* end = head;
//		int k = 0;
//		while (end->next != tail)
//		{
//			end = end->next;
//		}
//		cout << "Enter the value of how much you want to rotate : " ;
//		cin >> k;
//		while (k < 0)
//		{
//			cout << "Invalid value Enter again : ";
//			cin >> k;
//		}
//		for (int i = 0; i < k; i++)//rotate till user value
//		{
//			head = start->next;
//			start->next = tail;
//			end->next = start;
//			start = head;
//			end = end->next;
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
//	int option = 0, data, no = 0, more = 0;
//	SortedSet<int> ss;
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
//	while (more == 0)
//	{
//		ss.rotate();
//		ss.print();
//		cout << "----------------Do you want to Rotate More-------------" << endl;
//		cout << "Enter \n0 for Yes\n1 for No" << endl;
//		cin >> more;
//	}
//	return 0;
//}
