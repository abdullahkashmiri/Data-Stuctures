////Question 2
////Write your code in C++ to implement the following functionality in Circular linked list :
////Insert : Inserts any given integers at the end of the circular linked list
////InsertBefore : Take two integers as an argument v1 and v2 and insert v1 before v2.
////		   Search : Search a given integer
////				Update : Updates a given integer with another integer
////					 Check : Check either the made is circular linked list or not.
//
//#include<iostream>
//using namespace std;
//
//class Node
//{
//public:
//	int data;
//	Node* next;
//	Node()// Time Complexity ->> Big O(1)
//	{
//		data = 0;
//		next = NULL;
//	}
//	Node(int d)// Time Complexity ->> Big O(1)
//	{
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
//			newnode->next = head;
//			return;
//		}
//		Node* current = head;
//		while (current->next!= head)
//		{
//			current = current->next;
//		}
//		newnode->next = head;
//		current->next = newnode;
//		
//	}
//	void insertBefore(int v1, int v2)// Time Complexity ->> Big O(n)
//	{
//		Node*newnode = new Node(v1);
//		if (head == NULL)
//		{
//			head = newnode;
//			newnode->next = head;
//			return;
//		}
//		Node * current = head;
//		while (current->next!=head)
//		{
//			if (current->data < v2 && current->next->data >= v2)
//			{
//				newnode->next = current->next;
//				current->next = newnode;
//				return;
//			}
//			current = current->next;
//		}
//		newnode->next = head;
//		current->next = newnode;
//	}
//	void Search(int d)// Time Complexity ->> Big O(n)
//	{
//		if (head == NULL)
//		{
//			return;
//		}
//		Node * current = head;
//		int i = 0;
//		while (current->next!=head)
//		{
//			if (current->next->data == d)
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
//		while (current->next != head)
//		{
//			cout << current->next->data << ",";
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
//		while (current->next != head)
//		{
//			if (current->next->data == v2)
//				current->next->data = v1;
//			current = current->next;
//		}
//	}
//	bool check()// Time Complexity ->> Big O(n)
//	{
//		if (head == NULL)
//		{
//			return true;
//		}
//		Node * current = head;
//		while (current->next != head)
//		{
//			current = current->next;
//		}
//		if (current->next == head)
//		{
//			return true;
//		}
//		return false;
//	}
//
//
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
//	cout << "INSERT BEFORE" << endl;
//
//	dll.insertBefore(9, 20);
//	dll.print();
//	cout << "UPDATE" << endl;
//
//	dll.update(100, 2);
//	dll.print();
//	cout << "CHECK" << endl;
//
//	if (dll.check() == true)
//	{
//		cout << "yes its circular Linked List" << endl;
//	}
//	else
//		cout << "No its not circular Linked List" << endl;
//
//	system("pause");
//	return 0;
//}