//#include<iostream>
//#include<fstream>
//#include<string>
//#include<sstream>
//
//using namespace std;
//template<class K, class V>
//class Heapitem
//{
//public:
//	K key;
//	V value;
//	Heapitem()
//	{
//		key = -1;
//		value = -1;
//	}
//};
//template<class K, class V>
//class MinHeap
//{
//private:
//	Heapitem<K, V> * arr;
//	int capacity;
//	int totalitems;
//	int parent(int index)//return parent index
//	{
//		return(index - 1) / 2;
//	}
//	int leftchild(int index)//return left child index
//	{
//		return(2 * index + 1);
//	}
//	int rightchild(int index)//return right child index
//	{
//		return (2 * index + 2);
//	}
//public:
//	MinHeap()//default constructor
//	{
//		arr = NULL;
//		capacity = 0;
//		totalitems = 0;
//	}
//	MinHeap(int cap)//overloaded constructor
//	{
//		capacity = cap;
//		totalitems = 0;
//		arr = new Heapitem<K, V>[cap];
//		cout << "Current size : " << totalitems << "\tCapacity : " << capacity << endl;
//	}
//	void Update_size()//make heap array of double size
//	{
//		cout << "Size Updated DOUBLED" << endl;
//		int org = capacity;
//		capacity *= 2;
//		Heapitem<K, V> * tarr = new Heapitem<K, V>[capacity];
//		for (int i = 0; i < org; i++)
//		{
//			tarr[i].key = arr[i].key;
//			tarr[i].value = arr[i].value;
//		}
//		delete[]arr;
//		arr = tarr;
//		cout << "Current size : " << totalitems << "\tCapacity : " << capacity << endl;
//	}
//	void heapup(int index)// swap till given index gets on lowest position
//	{
//		while (index != 0 && arr[parent(index)].key > arr[index].key)
//		{
//			K tempkey = arr[parent(index)].key;
//			V tempvalue = arr[parent(index)].value;
//			arr[parent(index)].key = arr[index].key;
//			arr[parent(index)].value = arr[index].value;
//			arr[index].key = tempkey;
//			arr[index].value = tempvalue;
//			index = parent(index);
//		}
//	}
//	void insert(K key, V value)// insert function
//	{
//		if (totalitems == capacity)// full size
//		{
//			cout << "HEAP IS FULL" << endl;
//			Update_size();
//		}
//		totalitems++;//inc
//		int index = totalitems - 1;//placing at last index of filled array
//		arr[index].key = key;
//		arr[index].value = value;
//		cout << "Inserted Key : " << arr[index].key << "\t Value : " << arr[index].value << endl;
//		heapup(index);// sort heap by swapping
//	}
//	void getMin(V &val)
//	{
//		if (arr[0].value != NULL && !arr)
//		{
//			cout << "Empty Heap" << endl;
//			val = -9999;
//		}
//		else
//		{
//			val = arr[0].value;
//		}
//	}
//	void deleteMin()
//	{
//		if (!arr)
//		{
//			cout << "Empty Heap arr" << endl;
//			return;
//		}
//		totalitems--;
//		arr[0].key = arr[totalitems].key;
//		arr[0].value = arr[totalitems].value;
//		arr[totalitems].key = -1;
//		arr[totalitems].value = -1;
//		Minupdate(0);
//	}
//	void Minupdate(int index)
//	{
//		int left = leftchild(index);
//		int right = rightchild(index);
//		int min = index;
//
//		if (left < totalitems && arr[left].key < arr[index].key)
//			min = left;
//		if (right < totalitems && arr[right].key < arr[min].key)
//			min = right;
//		if (min != index)
//		{
//			K tempkey = arr[index].key;
//			V tempvalue = arr[index].value;
//			arr[index].key = arr[min].key;
//			arr[index].value = arr[min].value;
//			arr[min].key = tempkey;
//			arr[min].value = tempvalue;
//			Minupdate(min);
//		}
//	}
//	void Print()
//	{
//		cout << "Printing Heap" << endl;
//		for (int i = 0; i < totalitems; i++)
//		{
//			cout << "Key : " << arr[i].key << "\t Value : " << arr[i].value << endl;
//		}
//		cout << "Current size : " << totalitems << " Capacity : " << capacity << endl;
//	}
//	bool isEmpty()
//	{
//		if (!arr)
//		{
//			cout << "Empty Heap" << endl;
//			return true;
//		}
//		if (arr[0].key == -1)
//		{
//			cout << "Empty Heap" << endl;
//			return true;
//		}
//		else
//			return false;
//	}
//	~MinHeap()
//	{
//		delete[]arr;
//	}
//};
//
////Create a student class which contains rollNumber as int, name as string, and cgpa as float.
////Implement any constructors, getters and setters.
//
//class Student
//{
//private:
//	int rollno;
//	string name;
//	float cgpa;
//public:
//	Student()
//	{
//		rollno = 0;
//		name ;
//		cgpa = 0.0;
//	}
//	void setrollno(int a)
//	{
//		rollno = a;
//	}
//	void setname(string a)
//	{
//		name = a;
//	}
//	void setcgpa(float a)
//	{
//		cgpa = a;
//	}
//	int getrollno()
//	{
//		return rollno;
//	}
//	string getname()
//	{
//		return name;
//	}
//	float getcgpa()
//	{
//		return cgpa;
//	}
//	friend ostream &operator<<(ostream & out, const Student &s)
//	{
//		cout << "Student Data " << endl;
//		out << "Roll No : " << s.rollno << " Name : " << s.name << " CGPA : " << s.cgpa << endl;
//		return out;
//	}
//	
//};
//
///*
//Implement a function buildStudentHeap which takes as argument a file name and an initially
//empty min heap object by reference. Your task is to read student data from the file and insert
//Student objects into the min heap. The key will be roll number.
//void buildStudentHeap(string fileName, MinHeap&lt;int, Student&gt; &amp;stdHeap)
//*/
//
//void buildStudentHeap(string filename,MinHeap<int,Student>&stdHeap)
//{
//	ifstream file;
//	file.open(filename);
//	if (file.fail())
//	{
//		cout << "Error file not loaded " << endl;
//	}
//	else
//		cout << "File Found Successfully" << endl;
//	string line;
//	while (getline(file, line)&&!file.eof())
//	{
//
//	}
//
//}
//int main()
//{
//	MinHeap<int, int>mh(2);
//	mh.insert(3, 3);
//	mh.insert(7, 7);
//	mh.insert(4, 4);
//	mh.insert(0, 0);
//	mh.insert(5, 5);
//
//	mh.Print();
//	int val;
//	mh.getMin(val);
//	if (val != -9999)
//		cout << "Get Value : " << val << endl;
//	cout << "Before Delete Min" << endl;
//	mh.Print();
//	cout << "After Delete Min" << endl;
//	mh.deleteMin();
//	mh.Print();
//	if (mh.isEmpty())
//	{
//		cout << "Empty Heap" << endl;
//	}
//	else
//		cout << "Not Empty Heap" << endl;
//
//	cout << "\n\nSystem Terminated SuccessFully" << endl;
//	system("pause");
//
//	
//	//MinHeap<int, Student>stdheap;
//
//		
//
//		system("pause");
//	return 0;
//}