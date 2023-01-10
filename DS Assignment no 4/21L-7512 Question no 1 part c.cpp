//#include<iostream>
//#include<sstream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//template<class K, class V>
//class Node// Node class template based
//{
//public:// Data members
//	K key;
//	V value;
//	Node* left;
//	Node* right;
//	int height;
//	Node()//Default constructor
//	{
//		key = NULL;
//		value = NULL;
//		left = NULL;
//		right = NULL;
//		height = 0;
//	}
//	Node(K k, V v)// Overloaded constructor
//	{
//		key = k;
//		value = v;
//		left = NULL;
//		right = NULL;
//		height = 0;
//	}
//};
//
//template<class K, class V>
//class SpecialBST// Special BST class Template based
//{
//private://private data members
//	Node<K, V>* Root;
//	bool flag_insertion;
//	bool flag_key;
//	bool leafnodeflag;
//	vector<pair<K, V>>traverse;
//public:// member functions
//	SpecialBST()//Constructor
//	{
//		Root = NULL;
//		flag_insertion = false;
//		flag_key = false;
//		leafnodeflag = false;
//	}
//	~SpecialBST()//Destructor
//	{
//		cout << "Destructor here" << endl;
//		Destroy(Root);
//	}
//	void Destroy(Node<K, V>*& node)//Destroy member function for destructor
//	{
//		if (node)
//		{
//			Destroy(node->left);
//			Destroy(node->right);
//			delete node;
//		}
//	}
//	//----------------------------------------------------------------------------------------------------
//	// INSERT FUNCTION
//	//----------------------------------------------------------------------------------------------------
//	bool insert(K key, V value)// Insert wrapped function
//	{
//		flag_insertion = false;// initillizing to false insertion flag 
//		Root = insertR(Root, key, value);// Recursive Insertion
//		if (flag_insertion)
//		{
//			cout << "Inserted SuccessFully Key : " << key << " Value : " << value << endl;
//		}
//		else
//			cout << "Duplicate Exist Key : " << key << " Value : " << value << endl;
//		return flag_insertion;// returning flag value
//	}
//	Node<K, V>* insertR(Node <K, V>* node, K key, V value)// recursive insertion function
//	{
//		if (node == NULL)//leaf node reached
//		{
//			Node<K, V>* newnode = new Node<K, V>(key, value);// make newnode 
//			flag_insertion = true;// inserted successfully
//			return newnode;
//		}
//		else if (node->key > key)// left child condition
//		{
//			Node<K, V>* newnode = insertR(node->left, key, value);// inserting new node at left
//			node->left = newnode->right;// left child of parent node pointing to new node right child
//			newnode->right = node;//newnode right child pointing to parent node
//			return newnode;// return back newnode
//		}
//		else if (node->key < key)// right child condition
//		{
//			Node<K, V>* newnode = insertR(node->right, key, value);// inserting new node aty the right 
//			node->right = newnode->left;// right child of parent node pointing to new node left child
//			newnode->left = node;//new node left child pointing to parent node
//			return newnode;// return back newnode
//		}
//		else if (node->key == key)// duplicate key
//		{
//			flag_insertion = false;// flag false duplication
//			return node;// return back parent node
//		}
//	}
//	//----------------------------------------------------------------------------------------------------
//	// SEARCH FUNCTION
//	//----------------------------------------------------------------------------------------------------
//	V* Search(K key)// search function wrapper function
//	{
//		flag_key = false;// making found flag false
//		Root = searchR(Root, key);// recursive function for searching
//		if (flag_key == true)	// true if found so return value
//		{
//			return (&Root->value);// return value of root because searched element is at root now
//		}
//		else
//		{
//			return nullptr;// else return nullptr
//		}
//	}
//	Node<K, V>* searchR(Node<K, V>* node, K key)// recursive function for search
//	{
//		if (node == NULL)// leaf node reached
//		{
//			flag_key = false;// flag to false not found
//			return NULL;// return  NULL ptr
//		}
//		else if (key == node->key)// Key found
//		{
//			flag_key = true;// update flag
//			return node;
//		}
//		else if (node->key > key)//left child case
//		{
//			Node<K, V>* newnode = searchR(node->left, key); //Right Rotation
//			if (newnode == NULL)//not found
//			{
//				return node;// return parent node
//			}
//			node->left = newnode->right;//pointing node left child to newnode right child
//			newnode->right = node;// pointing newnode right child to parent node
//			return newnode;//returning newnode
//		}
//		else if (node->key < key)//right child case
//		{
//			Node<K, V>* newnode = searchR(node->right, key);//left rotation
//			if (newnode == NULL)//not found
//			{
//				return node;
//			}
//			node->right = newnode->left;// pointing parent node right to newnode left
//			newnode->left = node;// pointing newnode left to parent
//			return newnode;//returning newnode
//		}
//	}
//	//----------------------------------------------------------------------------------------------------
//	// DELETION FUNCTION
//	//----------------------------------------------------------------------------------------------------
//	bool delete_(K key)// wrapper function for delete
//	{
//		flag_key = false;// making found flag false
//		if (Search(key))
//		{
//			deleteR(Root, key);// recursive function for searching
//			return true;
//		}
//		return false;
//	}
//	void deleteR(Node<K, V>*& node, K key)
//	{
//		if (key > node->key)
//		{
//			deleteR(node->right, key);
//		}
//		else if (key < node->key)
//		{
//			deleteR(node->left, key);
//		}
//		else
//			delete_Node(node);
//	}
//	void delete_Node(Node<K, V>*& node)// delet node function
//	{
//		K keyy;
//		Node<K, V>* temp = node;
//		if (node->left == NULL)// right child exit
//		{
//			node = node->right;
//			delete temp;
//		}
//		else if (node->right == NULL)// left child exits
//		{
//			node = node->left;
//			delete temp;
//		}
//		else// both child case
//		{
//			getPredecessor(node->left, keyy);// left largest node
//			node->key = keyy;
//			deleteR(node->left, keyy);// delete that node
//		}
//	}
//	void getPredecessor(Node<K, V>* node, K& key)// last node of one side
//	{
//		while (node->right != NULL)
//		{
//			node = node->right;
//		}
//		key = node->key;
//	}
//	//-----------------------------------------------------------------------------
//	// Get Values fnunction level wise
//	//-----------------------------------------------------------------------------
//	vector<pair<K, V>>* getValuesLevelWise()//function get values wise
//	{
//		traverse.clear();//clearing vector
//		levelOrderR(Root);// getting values level wise
//		return &traverse;// returning vector
//	}
//	void levelOrderR(Node<K, V>* node)
//	{
//		if (node == NULL)//empty tree
//		{
//			return;
//		}
//		queue<Node<K, V>*>Q;// dynamic queue
//		Q.push(node);
//		while (!Q.empty())
//		{
//			Node<K, V>* front = Q.front();
//			Q.pop();
//			traverse.push_back(make_pair(front->key, front->value));//pushing values
//			if (front->left != NULL)
//			{
//				Q.push(front->left);
//			}
//			if (front->right != NULL)
//			{
//				Q.push(front->right);
//			}
//		}
//	}
//	//-----------------------------------------------------------------------------
//	// Get Values function order wise
//	//-----------------------------------------------------------------------------
//	vector<pair<K, V>>* getValuesInOrder()// values in order function
//	{
//		traverse.clear();// clearing vector
//		inorderR(Root);// getting values in order recursively
//		return&traverse;// returining vector
//	}
//	void inorderR(Node<K, V>* node)// inorder traversal of tree
//	{
//		if (node)
//		{
//			inorderR(node->left);
//			traverse.push_back(make_pair(node->key, node->value));//getting values in vector
//			inorderR(node->right);
//		}
//	}
//	//-----------------------------------------------------------------------------
//	// Printing Function
//	//-----------------------------------------------------------------------------
//	void PostOrder()//post order printing
//	{
//		cout << "Post Order Printing" << endl;
//		PostOrderR(Root);
//		cout << endl;
//	}
//	void PostOrderR(Node<K, V>*& node)// post order recursive
//	{
//		if (node)
//		{
//			PostOrderR(node->left);
//			PostOrderR(node->right);
//			cout << "Node Key : " << node->key << " Node Value : " << node->value << endl;
//		}
//	}
//	void PreOrder()// preorder printig
//	{
//		cout << "Pre Order Printing" << endl;
//		PreOrderR(Root);
//		cout << endl;
//	}
//	void PreOrderR(Node<K, V>*& node)// preorder printing recursively
//	{
//		if (node)
//		{
//			cout << "Node Key : " << node->key << " Node Value : " << node->value << endl;
//			PreOrderR(node->left);
//			PreOrderR(node->right);
//		}
//	}
//};
//
//template<class K, class V>//template based print function
//void printVector(vector<pair<K, V>>* traverse)
//{
//	for (int i = 0; i < traverse->size(); i++)//traverse till vector size
//	{
//		cout <<"KEY : "<< traverse->at(i).first << ", VALUE : " << traverse->at(i).second << endl;// print key and value
//
//	}
//	cout << endl;
//}
//
//template<class K, class V>// template class student
//class Student
//{
//public:// data members
//	string firstname;
//	string lastname;
//	int batch;
//	string department;
//	float cgpa;
//	Student()// default constructor 
//	{
//		firstname = '\0';
//		lastname = '\0';
//		batch = 0;
//		department = '\0';
//		cgpa = 0.0;
//	}
//	void insert(string f, string l, int b, string d, float c)//updation function for data members
//	{
//		firstname = f;
//		lastname = l;
//		batch = b;
//		department = d;
//		cgpa = c;
//	}
//	void print()
//	{
//		cout << "First Name : " << firstname << "\tLast Name : ";
//		cout << lastname << "\tBatch : " << batch << "\tDepartment Name : ";
//		cout << department << "\tCGPA : " << cgpa << endl;
//	}
//	friend ostream& operator << (ostream& out, const Student& s)  // overloaded function cout for object of this class
//	{
//		out << "\tFirst Name : " << s.firstname;
//		out << "\tlast Name : " << s.lastname;
//		out << "\tBatch : " << s.batch;
//		out << "\tDepartment : " << s.department;
//		out << "\t\tCGPA : " << s.cgpa;
//		return out;
//	}
//};
//
//template<class K, class V>// template based student list class
//class StudentList : public Student<K, V>, SpecialBST<K, V>
//{
//private:// private data members
//	Student<K, V> student;
//	SpecialBST<K, Student<K, V>> SBST;
//public:
//	StudentList()//default constructor
//	{
//		//SBST = NULL;
//		//student = NULL;
//	}
//	bool insertNewStudent(int roll, string first, string last, int bat, string dept, float gpa)// insert function
//	{
//		student.insert(first, last, bat, dept, gpa);
//		bool flag = SBST.insert(roll, student);
//		if (flag == true)
//		{
//			cout << "inserted SuccessFully" << endl << endl;
//		}
//		else
//			cout << "Duplicate exist" << endl << endl;
//		return flag;
//	}
//	bool deleteStudent(int rollno)// delete function student object
//	{
//
//		bool flag = SBST.delete_(rollno);
//		if (flag == true)
//		{
//			cout << "Deleted SuccessFully" << endl;
//		}
//		else
//			cout << "No Record Found" << endl;
//		return flag;
//	}
//	bool updateStudent(int oldroll, int newroll, string first, string last, int batch, string dept, float gpa)// upadte student function 
//	{
//		student.insert(first, last, batch, dept, gpa);
//		if (SBST.Search(oldroll))
//		{
//			cout << "Record found" << endl;
//			SBST.PostOrder();
//			if (SBST.Search(newroll))
//			{
//				cout << "NEW ROLL NO ALREADY EXIST" << endl;
//				return false;
//			}
//			SBST.delete_(oldroll);
//			SBST.insert(newroll, student);
//		}
//		else
//		{
//			cout << "Record not found" << endl;
//			return false;
//		}
//		return true;
//	}
//	void SearchStudent(int rollno)
//	{
//		cout << "Searching Roll no : " << rollno << endl;
//		if (SBST.Search(rollno))
//		{
//			cout << "Found in Record : " << endl;
//			cout << "Key : " << rollno << " Value : " << SBST.Search(rollno) << endl;
//		}
//		else
//			cout << "No Record Found" << endl;
//	}
//	void PrintAllStudents()//Printing All students
//	{
//		cout << "Printing ALL Students" << endl;
//		printVector(SBST.getValuesInOrder());
//		cout << endl;
//	}
//	~StudentList()
//	{
//		cout << "Destructor here" << endl;
//	}
//};
//void PRINING_CONTENT()//Menu printing
//{
//	cout << "Press I to insert a new Student." << endl;
//	cout << "Press D to delete a Student." << endl;
//	cout << "Press S to search a Student." << endl;
//	cout << "Press U to update a Student." << endl;
//	cout << "Press P to print all Studenta by sorted Roll Number." << endl;
//	cout << "Press C to Clear Screen." << endl;
//	cout << "Press E to exit." << endl;
//}
//
//int main()
//{
//	StudentList <int, string> students;
//
//	bool live = true;
//	char input;
//	string str, word;
//	string first, last, dept;
//	float cgpa;
//	int rollno, batch, newrollno;
//
//	while (live)
//	{
//		PRINING_CONTENT();
//		cout << "ENTER KEY - >> ";
//		cin >> input;
//		while (input != 'I' && input != 'i' && input != 'D' && input != 'd' && input != 'S' && input != 's' && input != 'U' && input != 'u' && input != 'P' && input != 'p' && input != 'E' && input != 'e' && input != 'C' && input != 'c')
//		{
//			cout << "InValid Input \tEnter Again : ";
//			cin >> input;
//		}
//		//system("CLS");
//		if (input == 'I' || input == 'i')
//		{
//			cout << "Please enter the data of new student in the order:";
//			cout<<"\nRoll Number, First Name, Last Name, Batch, Department, CGPA" << endl;
//			cout << "Example ->> 29 Hammad Tariq 2020 CV 2.50" << endl;
//			cout << "ROLL NUMBER : ";
//			cin >> rollno;
//			while (rollno < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> rollno;
//			}
//			cout << "FIRST NAME : ";
//			cin >> first;
//			cout << "LAST NAME : ";
//			cin >> last;
//			cout << "BATCH : ";
//			cin >> batch;
//			while (batch < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> batch;
//			}
//			cout << "DEPARTMENT : ";
//			cin >> dept;
//			cout << "CGPA : ";
//			cin >> cgpa;
//			while (cgpa < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> cgpa;
//			}
//			students.insertNewStudent(rollno, first, last, batch, dept, cgpa);
//		}
//		if (input == 'D' || input == 'd')
//		{
//			cout << "Enter ROLL NO of Student : ";
//			cin >> rollno;
//			while (rollno < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> rollno;
//			}
//			students.deleteStudent(rollno);
//		}
//		if (input == 'S' || input == 's')
//		{
//			cout << "Enter ROLL NO of Student : ";
//			cin >> rollno;
//			while (rollno < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> rollno;
//			}
//			students.SearchStudent(rollno);
//		}
//		if (input == 'U' || input == 'u')
//		{
//			cout << "Enter OLD ROLL NO of Student : ";
//			cin >> rollno; 
//			while (rollno < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> rollno;
//			}
//			cout << "NEW ROLL NUMBER : ";
//			cin >> newrollno;
//			while (newrollno < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> newrollno;
//			}
//			cout << "NEW FIRST NAME : ";
//			cin >> first;
//			cout << "NEW LAST NAME : ";
//			cin >> last;
//			cout << "NEW BATCH : ";
//			cin >> batch;
//			while (batch < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> batch;
//			}
//			cout << "NEW DEPARTMENT : ";
//			cin >> dept;
//			cout << "NEW CGPA : ";
//			cin >> cgpa;
//			while (cgpa < 1)
//			{
//				cout << "Invalid inputs Enter Again : ";
//				cin >> cgpa;
//			}
//			if (students.updateStudent(rollno, newrollno, first, last, batch, dept, cgpa))
//				cout << "Updated SuccessFully" << endl;
//			else
//				cout << "No Updation" << endl;
//		}
//		if (input == 'P' || input == 'p')
//		{
//			students.PrintAllStudents();
//		}
//		if (input == 'E' || input == 'e')
//		{
//			cout << "EXITING PROGRAM" << endl;
//			live = false;
//		}
//		if (input == 'C' || input == 'c')
//		{
//			system("CLS");
//		}
//	}
//	return 0;
//}
//////---------------------------------------------------------------------------------------