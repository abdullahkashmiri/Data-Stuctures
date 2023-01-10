//#include<iostream>
//using namespace std;
//
//template<class T>
//class Node
//{
//public:
//	T data;
//	Node <T> *next;
//
//	Node()  // default constructor
//	{
//		data = 0;
//		next = NULL;
//	}
//	Node(T da)  //parametarized constructor
//	{
//		data = da;
//		next = NULL;
//	}
//	~Node()
//	{
//		delete next;
//	}
//};
//
//template<class T>
//class LinkedList
//{
//private:
//	Node <T> *head;
//public:
//	LinkedList()//default constructor
//	{
//		head = NULL;
//	}
//	void insertAtStart(T const element)//insert at start
//	{
//		Node <T> *newNode = new Node <T>(element);
//		if (head == NULL)
//		{
//			head = newNode;
//		}
//		else{
//			newNode->next = head;
//			head = newNode;
//		}
//	}
//	void insertAtEnd(T const element)//insert at end
//	{
//		Node <T> *newNode = new Node<T>(element);
//		if (head == NULL)
//		{
//			head = newNode;
//			return;
//		}
//		Node <T>*temp = head;
//		while (temp->next != NULL)
//		{
//			temp = temp->next;
//		}
//		temp->next = newNode;
//	}
//	void print() const//printing function
//	{
//		Node <T> *temp = head;
//		if (head == NULL)
//		{
//			cout << "List is Empty!!" << endl;
//			return;
//		}
//		cout << "List is : ";
//		while (temp != NULL)
//		{
//			cout << temp->data << ",";
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//	bool search(T const& element) const
//	{
//		cout << "Checking " << element << endl;
//		if (head != NULL)
//		{
//			Node <T> *temp = head;
//			while (temp->next != NULL)
//			{
//				if (temp->data == element)
//				{
//				
//					return true;
//				}
//				temp = temp->next;
//			}
//		}
//		return false;
//	}
//	bool isEmpty() const
//	{
//		if (head == NULL)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool insertBefore(T const v1, T const v2) const
//	{
//		if (head != NULL)
//		{
//			Node <T> * temp = head;
//			Node <T> * prev = temp;
//			Node <T> *newNode = new Node<T>(v1);
//
//			while (temp->next != NULL)
//			{
//				if (temp->data == v2)
//				{
//				newNode->next = temp;
//					prev->next = newNode;
//					
//
//					return true;
//				}
//				prev = temp;
//				temp = temp->next;
//				
//			}
//
//			return false;
//
//		}
//	}
//
//	void deleteAll(T const value)
//	{
//		if (head != NULL)
//		{
//			Node <T> * temp = head;
//			Node <T> * prev = temp;
//			while (temp->next != NULL)
//			{
//				if (temp->data == value)
//				{
//					temp = temp->next;
//					prev->next = temp->next;
//					
//				}
//				prev = temp;
//				temp = temp->next;
//
//				
//				
//			}
//
//
//		}
//	}
//
//
//	void DeleteAtStart()
//	{
//		if(head != NULL)
//		{
//			Node <T> * temp = head;
//			head = temp->next;
//		}
//	}
//	~LinkedList()
//	{
//		delete head;
//	}
//
//	};
//
//	int main()
//	{
//		LinkedList <int> list;
//		list.insertAtStart(2);
//		list.insertAtStart(6);
//		list.insertAtStart(7);
//		list.print();
//		list.insertAtEnd(9);
//		list.print();
//		list.insertAtStart(7);
//		list.insertAtStart(8);
//		list.insertAtStart(9);
//
//		list.print();
//		cout << "eleminiting a value 7 : " << endl;
//		list.deleteAll(7);
//
//		list.print();
//		if (list.search(2) == 1)
//		{
//			cout << "found" << endl;
//		}
//		else
//			cout << "Not Found" << endl;
//		list.print();
//		if (list.search(9) == 1)
//		{
//			cout << "found" << endl;
//		}
//		else
//			cout << "Not Found" << endl;
//		list.print();
//		if (list.search(10) == 1)
//		{
//			cout << "found" << endl;
//		}
//		else
//			cout << "Not Found" << endl;
//		list.DeleteAtStart();
//		list.print();
//		cout << "List checking if empty : " << endl;
//		if (list.isEmpty() == 1)
//		{
//			cout << "empty" << endl;
//		}
//		else
//			cout << "Not empty" << endl;
//		cout << "inserting 10 before 2 : " << endl;
//		if (list.insertBefore(10, 2) == 1)
//		{
//			cout << "Inserted" << endl;
//		}
//		else
//		{
//			cout << "Not inserted" << endl;
//		}
//		list.print();
//		system("pause");
//		return 0;
//	}