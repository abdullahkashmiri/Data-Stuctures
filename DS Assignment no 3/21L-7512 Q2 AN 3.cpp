//#include<iostream>
//using namespace std;
//
//template<class T>
//class Node//Node class
//{
//public:
//	T data;
//	Node* next;
//	Node()//default constructor
//	{
//		data = NULL;
//		next = NULL;
//	}
//	Node(T d)//overloaded constructor
//	{
//		data = d;
//		next = NULL;
//	}
//};
//template<class T>
//class Queue//Queue class
//{
//private:
//	Node <T>* front;
//	Node <T>* rear;
//	int size;
//public:
//	Queue()//default constructor
//	{
//		front = NULL;
//		rear = NULL;
//		size = 0;
//	}
//	void EnQueue(T data)//Insertion
//	{
//		Node<T>* newnode = new Node<T>(data);
//		if (rear == NULL)//empty queue
//		{
//			front = newnode;
//			rear = newnode;
//		}
//		else//if queue has already some elements
//		{
//			rear->next = newnode;
//			rear = rear->next;
//		}
//		size++;//size increse with insertion
//	}
//	T DeQueue()//Deletion with popping
//	{
//		if (!IsEmpty())//if queue has elements
//		{
//			T data = front->data;//saving data
//			Node <T>* temp = front;//saving node
//			front = front->next;
//			delete temp;//deleting node
//			size--;
//			if (size == 0)//making NULL
//			{
//				front = rear = NULL;
//			}
//			return data;//returning data
//		}
//		return NULL;//else return null
//	}
//	int Size()//function for getting size
//	{
//		return size;
//	}
//	bool IsEmpty()//checking if queue is empty
//	{
//		if (size == 0)
//		{
//			front = rear = NULL;//making pointers null
//			return true;
//		}
//		return false;
//	}
//	void Print(Queue q)//function for printing Queue
//	{
//		Node<T>* current = q.front;
//		for (int i = 0; current != NULL; i++)
//		{
//			cout << current->data << "  ";
//			current = current->next;
//		}
//	}
//};
//template<class T>
//void Radix_Sort_int(Queue<T>* q, int n, int k, int m)
//{
//	Queue<T>* temp = new Queue<T>[m];//temp queue
//	T original;//for extracting numbers
//	T index_locate;//extracting locations
//	int divlimit = 0;
//	int check = 9;
//	for (int i = 0; i < k-1; i++)//max number calculations
//	{
//		check = check * 10;
//		check += 9;
//	}
//	for (int i = 0; i < n; i++)//checking if number is greater than limit digits
//	{
//		original = q[i].DeQueue();
//		if (original > check)
//		{
//			divlimit = 1;
//		}
//		q[i].EnQueue(original);
//	}
//	if (divlimit == 1)//exit 
//	{
//		cout << "LIST REJECTED \nNO SORTING " << endl;
//		return;
//	}
//	for (int a = 0; a < k; a++)//number of digits
//	{
//		for (int i = 0; i < n; i++)//number of elements in queuee
//		{
//			original = q[i].DeQueue();
//			index_locate = original;
//			for (int j = 0; j < divlimit; j++)//divding number to get exact loc
//			{
//				index_locate /= 10;
//			}
//			index_locate = index_locate % 10;//mod for loc
//			temp[index_locate].EnQueue(original);//placing on specific index
//		}
//		for (int i = 0, j = 0; i < m; i++)//sending back to original queue
//		{
//			while (!temp[i].IsEmpty())
//			{
//				original = temp[i].DeQueue();
//				q[j].EnQueue(original);
//				j++;
//			}
//		}
//		divlimit++;
//	}
//}
//int Check_String_Size(string s)//counting no of char in string
//{
//	int count = 0;
//	while (s[count] != NULL)
//	{
//		count++;
//	}
//	return count;
//}
//template<class T>
//void Radix_Sort_char(Queue<T>* q, int n, int k, int m)
//{
//	Queue<T>* temp = new Queue<T>[m];//temp queue
//	T original;
//	int index_locate;
//	int check = 1;
//	for (int i = 0; i < n; i++)//checking if string has not same numbers as limit
//	{
//		original = q[i].DeQueue();
//		if (Check_String_Size(original) != k)
//		{
//			cout << "Error Occurred \nIndex no : " << i << " data : " << original << " size issue." << endl;
//			check = 0;
//		}
//		q[i].EnQueue(original);
//	}
//	if (check == 0)//exit
//	{
//		cout << "LIST REGECTED \nNO SORTING " << endl;
//		return;
//	}
//	for (int a = k - 1; a >= 0; a--)//number of chars
//	{
//		for (int i = 0; i < n; i++)//number of string/words
//		{
//			original = q[i].DeQueue();
//			index_locate = original[a];//placing at calculated index
//			temp[index_locate].EnQueue(original);
//		}
//		for (int i = 0, j = 0; i < m; i++)//moving back to original queue
//		{
//			while (!temp[i].IsEmpty())
//			{
//				original = temp[i].DeQueue();
//				q[j].EnQueue(original);
//				j++;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	Queue <int>* Qint;
//
//	int n, k, m, data = 0;
//	string str;
//	n = k = m = 0;
//
//	cout << "Integer Sorting Here " << endl;
//	cout << "How many Number you want to add : ";
//	cin >> n;
//	while (n < 0)
//	{
//		cout << "Illegal input : ";
//		cin >> n;
//	}
//	cout << "How many digits each number have : ";
//	cin >> k;
//	while (k < 1)
//	{
//		cout << "Illegal input : ";
//		cin >> k;
//	}
//	m = 10;
//	Qint = new Queue<int>[n];
//	cout << "Enter Data in Queue  " << endl;
//	for (int i = 0; i < n; i++)//insertion in queue int
//	{
//		cout << " Index no : " << i << " : ";
//		cin >> data;
//		while (data < 0)
//		{
//			cout << "Illegal Inputs : ";
//			cin >> data;
//		}
//		Qint[i].EnQueue(data);
//	}
//
//	cout << "PRINTING UN-SORTED QUEUE (INT)." << endl;
//	for (int j = 0; j < n; j++)
//	{
//		Qint->Print(Qint[j]);
//		cout << endl;
//	}
//	
//	Radix_Sort_int(Qint, n, k, m);
//	
//	cout << "PRINTING QUEUE (INT)." << endl;
//	for (int j = 0; j < n; j++)
//	{
//		Qint->Print(Qint[j]);
//		cout << endl;
//	}
//	cout << "Deletion / DEQUEUE" << endl;
//	for (int i = 0; i < n; i++)//deletinon in queue int
//	{
//		cout << Qint[i].DeQueue() << endl;
//	}
//	//////////////////////////////////////////////////////////////////
//	cout << "Characters Sorting Here " << endl;
//	cout << "How many words you want to add : ";
//	cin >> n;
//	while (n < 0)
//	{
//		cout << "Illegal input : ";
//		cin >> n;
//	}
//	cout << "How many characters each word have : ";
//	cin >> k;
//	while (k < 1)
//	{
//		cout << "Illegal input : ";
//		cin >> k;
//	}
//	m = 256;
//	Queue <string>* Qchar;
//	Qchar = new Queue<string>[n];
//	cout << "Enter Data in Queue  " << endl;
//	for (int i = 0; i < n; i++)//insetrin in queue char
//	{
//		cout << " Index no : " << i << " : ";
//		cin >> str;
//		Qchar[i].EnQueue(str);
//	}
//	cout << "PRINTING UN-SORTED QUEUE (STRING)." << endl;
//	for (int j = 0; j < n; j++)
//	{
//		Qchar->Print(Qchar[j]);
//		cout << endl;
//	}
//	Radix_Sort_char(Qchar, n, k, m);
//	cout << "PRINTING QUEUE (STRING)." << endl;
//	for (int j = 0; j < n; j++)
//	{
//		Qchar->Print(Qchar[j]);
//		cout << endl;
//	}
//	cout << "Deletion / DEQUEUE" << endl;
//	for (int i = 0; i < n; i++)//deletion in queue char
//	{
//		cout << Qchar[i].DeQueue() << endl;
//	}
//	return 0;
//}