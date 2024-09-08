//#include<iostream>
//#include<fstream>
//#include<string>
//#include<sstream>
//#include<assert.h>
//using namespace std;
//
//template<class v>
//struct HashItem// hash item struct
//{
//	int key = 0;
//	v value;
//	short status = 0; //0 = Empty By default
//};
//
//template<class v>
//class HashMap // hash Map class
//{
//protected:
//	// protected Data Members
//	HashItem<v>*HashArray;
//	int capacity;
//	int currentElements;
//	// protected Member functions
//	virtual int getNextCandidateIndex(int key, int i)// linear probbing
//	{
//		int index = (key + i) % this->capacity;
//		if (HashArray[index].status == 0 || HashArray[index].status == 1)
//		{
//			return index;
//		}
//		return getNextCandidateIndex(key, i + 1);
//	}
//	void doublecapacity() // double capcity function
//	{
//		int oldcapacity = this->capacity;
//		this->capacity = 2 * this->capacity;
//		cout << "Capacity Doubled!! Old Capacity : " << oldcapacity << " New Capacity : " << this->capacity << endl;
//		HashItem<v>* tempArr = this->HashArray;	//pointing a pointer to hash item array
//		this->HashArray = new HashItem<v>[this->capacity];// making a new array of double capacity
//		this->currentElements = 0;
//		for (int i = 0; i < oldcapacity; i++)// inserting keys back via rehashing
//		{
//			if (tempArr[i].status == 2)// occupied status
//			{
//				cout << "Re-Hashing : ";
//				insert(tempArr[i].key, tempArr[i].value);
//			}
//		}
//		delete[]tempArr;// delete old heap array
//	}
//public:
//	HashMap()// default constructor
//	{
//		this->capacity = 7;
//		this->currentElements = 0;
//		this->HashArray = new HashItem<v>[this->capacity];
//	}
//	HashMap(int const capacity)// overloaded constructor
//	{
//		if (capacity < 1)
//		{
//			return assert(capacity > 1);// return via assert (assumption checking)
//		}
//		this->currentElements = 0;
//		this->HashArray = new HashItem<v>[this->capacity];
//	}
//	void insert(int const key, v const value)// insert function
//	{
//		if ((((float)(this->currentElements)) / ((float)(this->capacity))) >= (0.75))// computing load factor 
//		{
//			doublecapacity(); // if load factor is greater than 0.75
//		}
//		int index = key % this->capacity;// calcultion index
//		if (HashArray[index].status == 2)// if index is already occupied hash collosion
//		{
//			index = getNextCandidateIndex(key, 1);// rsolving hash collosion
//		}
//		this->HashArray[index].status = 2;// placing values
//		this->HashArray[index].key = key;
//		this->HashArray[index].value = value;
//		this->currentElements++;
//		cout << "Inserted Key : " << this->HashArray[index].key << "  Value : " << this->HashArray[index].value << endl;
//	}
//	bool deleteKey(int const key) const// delete function
//	{
//		for (int i = 0; i < this->capacity; i++)
//		{
//			if (this->HashArray[i].status == 2)// indexes that are occupied
//			{
//				if (this->HashArray[i].key == key)// key maches to occupied indexes
//				{
//					this->HashArray[i].status = 1;// setting statis to deleted
//					cout << "Key : " << this->HashArray[i].key << " Having Value : " << this->HashArray[i].value << " Deleted " << endl;
//					return true;
//				}
//			}
//		}
//		cout << key << "  Not Found for deletion!!" << endl;
//		return false;// if not found
//	}
//	v* get(int const key)const// value getting function
//	{
//		for (int i = 0; i < this->capacity; i++)
//		{
//			if (this->HashArray[i].status == 2)// indexes that are occupied
//			{
//				if (this->HashArray[i].key == key)// key maches to occupied indexes
//				{
//					return &(this->HashArray[i].value);// returning value of that key
//				}
//			}
//		}
//		cout << key<<"  Not found for searching" << endl;
//		return NULL;//if not found return nullptr
//	}
//	void PrintHashing()
//	{
//		for (int i = 0; i < capacity; i++)
//		{
//			if (HashArray[i].status == 2)
//			{
//				cout << "INDEX : " << i << " Key : " << HashArray[i].key << " Value : " << HashArray[i].value << endl;
//			}
//		}
//	}
//	~HashMap()//destructor
//	{
//		this->currentElements = 0;
//		this->capacity = 10;
//		delete []this->HashArray;
//	}
//};
//template<class v>// template class for quadratic probbing
//class QHashMap :public HashMap<v>
//{
//public:
//	int getNextCandidateIndex(int key, int i)
//	{
//		int index = (key + (i * i)) % this->capacity;// quadratic probbing
//		if (this->HashArray[index].status == 0 || this->HashArray[index].status == 1)// if free index found
//		{
//			return index;
//		}
//		return getNextCandidateIndex(key, i + 1);// if free index not  found
//	}
//};
//template<class v>
//class DHashMap: public HashMap<v>//template class for Double hashing 
//{
//public:
//	int getNextCandidateIndex(int key, int i)
//	{
//		int first_value = key % this->capacity;
//		int second_value = (7 - (key % 7));
//		int candidate_index = ((first_value + (i * second_value)) % this->capacity);// double hashing
//		if (this->HashArray[candidate_index].status == 0 || this->HashArray[candidate_index].status == 1)// if free index found
//		{
//			return candidate_index;
//		}
//		return getNextCandidateIndex(key, i + 1);// if free index not found
//	}
//};
//void PopulateHash(string filename, HashMap<string>* Hash)// function to populate hash array
//{
//	ifstream file;
//	file.open(filename);
//	if (file.fail())// if file is not open error
//	{
//		cout << "Error file Not Found" << endl;
//		return;
//	}
//	cout << "File Loaded Successfully" << endl;
//	string line, name;
//	int id;
//	int size;
//	file >> size;// getting size from file
//	file.ignore();// ignoring space in file
//	file.ignore();
//	for (int i = 0; i < size; i++)// while all students data is extracted
//	{
//		getline(file, line);
//		stringstream ss(line);
//		ss >> id;
//		ss >> name;
//		Hash->insert(id, name);
//	}
//}
//
//int main()
//{
//	cout << "-----------------LINEAR PROBING------------------" << endl;
//	HashMap<string>* map;
//	map = new HashMap<string>;
//	PopulateHash("students.txt", map);
//	cout << *map->get(9);
//	map->deleteKey(9);
//	assert(map->get(9) == NULL);
//	delete map;
//
//	cout << "-----------------QUADRATIC PROBING------------------" << endl;
//	map = new QHashMap<string>;
//	PopulateHash("students.txt", map);
//	cout << *map->get(98);
//	map->deleteKey(98);
//	assert(map->get(98) == nullptr);
//	delete map;
//
//	cout << "-----------------DOUBLE HASHING------------------" << endl;
//	map = new DHashMap<string>;
//	PopulateHash("students.txt", map);
//	cout << *map->get(101);
//	map->deleteKey(101);
//	assert(map->get(101) == nullptr);
//	delete map;
//	
//	cout << endl<< "Program Terminated Successfully" << endl;
//	system("pause");
//	return 0;
//}