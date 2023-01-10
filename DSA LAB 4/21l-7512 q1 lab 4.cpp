////Write your code in C++ to implement the following functionality in doubly linked list :
////Insert : Inserts any given integers at the end of the doubly linked list
////Search : Search a given integer
////	 Update : Updates a given integer with another integer
////		  InsertSorted : Make a function insertSorted that takes an element as argument and inserts in doubly
////						 linked list in sorted order
//
//#include<iostream>
//using namespace std;
//
//class Node
//{
//public:
//	Node *prev;
//	int data;
//	Node* next;
//	Node()// Time Complexity ->> Big O(1)
//	{
//		prev = NULL;
//		data = 0;
//		next = NULL;
//	}
//	Node(int d)// Time Complexity ->> Big O(1)
//	{
//		prev = NULL;
//		data = d;
//		next = NULL;
//	}
//};
//class DoublyLinkedList
//{
//private:
//	Node*head;
//public:
//	DoublyLinkedList()// Time Complexity ->> Big O(1)
//	{
//		head = NULL;
//	}
//	//insert at the end of doubly linked list
//	void InsertAtEnd(int data)// Time Complexity ->> Big O(n)
//	{
//		Node*newnode = new Node(data);
//		if (head == NULL)
//		{
//			head = newnode;
//			newnode->prev = head;
//			return;
//		}
//		Node* current = head;
//		while (current->next!= NULL)
//		{
//			current = current->next;
//		}
//		current->next = newnode;
//		newnode->prev = current;
//	}
//	void Search(int d)// Time Complexity ->> Big O(n)
//	{
//		if (head == NULL)
//		{
//			return;
//		}
//		Node * current = head;
//		int i = 0;
//		while (current!= NULL)
//		{
//			if (current->data == d)
//			{
//				cout << "data has been found at index : " << i << endl;
//				//return;
//			}
//			i++;
//			current = current->next;
//		}
//	}
//	void print() // Time Complexity ->> Big O(n)
//	{
//		if (head == NULL)
//		{
//			cout << "Empty List" << endl;
//			return;
//		}
//		Node * current = head;
//		cout << "List is : ";
//		while (current != NULL)
//		{
//			cout << current->data << ",";
//			current = current->next;
//		}
//		cout << endl;
//	}
//	void update(int v1, int v2) // Time Complexity ->> Big O(n)
//	{
//		if (head == NULL)
//		{
//			return;
//		}
//		Node * current = head;
//		while (current != NULL)
//		{
//			if (current->data == v2)
//				current->data = v1;
//			current = current->next;
//		}
//	}
//	void insert() // Time Complexity ->> Big O(n^2)
//	{
//		if (head == NULL)
//		{
//			return;
//		}
//
//		Node * current = head;
//		Node *next = current->next;
//		int temp = 0, size = 0;
//		while (current ->next != NULL)
//		{
//			size++;
//			current = current->next;
//		}
//		current = head;
//		for (int i = 0; i<size; i++)
//		{
//			current = head;
//			next = current->next;
//			while (next != NULL)
//			{
//				if (current->data > next->data)
//				{
//					temp = current->data;
//					current->data = next->data;
//					next->data = temp;
//				}
//				current = next;
//				next = next->next;
//			}
//		}
//	}
//	void insetsorted(int val)// Time Complexity ->> Big O(n^2)
//	{
//		insert();
//		Node *newnode = new Node(val);
//		if (head == NULL)
//		{
//			head = newnode;
//			newnode->prev = head;
//			return;
//		}
//		Node * current = head;
//		Node * next = current->next;
//
//		while (next != NULL)
//		{
//			if (current->data < val && next->data >= val)
//			{
//				newnode->prev = current;
//				newnode->next = current->next;
//				current->next->prev = newnode;
//				current->next= newnode;
//				return;
//			}
//			current = next;
//			next = next->next;
//		}
//		current->next = newnode;
//		newnode->prev = current;
//	
//		
//	}
//};
//
//int main()
//{
//	DoublyLinkedList dll;
//	dll.print();
//	cout << "INSERT AT END" << endl;
//	dll.InsertAtEnd(7);
//	dll.InsertAtEnd(2);
//	dll.InsertAtEnd(65);
//	dll.InsertAtEnd(2);
//	dll.InsertAtEnd(5);
//	dll.InsertAtEnd(0);
//	dll.InsertAtEnd(2);
//
//	dll.print();
//	cout << "SEARCH" << endl;
//
//	dll.Search(2);
//	dll.print();
//	cout << "UPDATE" << endl;
//	dll.update( 100,2);
//	dll.print();
//	cout << "INSERTED SORTED" << endl;
//	dll.insetsorted(10);
//	dll.print();
//
//
//	system("pause");
//	return 0;
//}