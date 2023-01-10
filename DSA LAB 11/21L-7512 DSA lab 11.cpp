//#include<iostream>
//#include<fstream>
//#include<string>
//#include<sstream>
//#include<cassert>
//
//using namespace std;
//
//template <class v>
//struct HashItem
//{
//	int key =0 ;
//	v value ;
//	short status = 0;  // empty = 0
//};
//
//template<class v>
//class HashMap
//{
//// protected:
//public:
//	HashItem<v>*hashArray;
//	int capacity;
//	int currentElements;
//	virtual int getNextCandidateIndex(int key, int i)
//	{
//		int index = (key + i) % capacity;
//		if ((hashArray[index].status == 0) || (hashArray[index + i].status == 1))
//		{
//			return i;
//		}
//		return getNextCandidateIndex(key, i + 1);
//	}
//	void doubleCapacity()
//	{
//		int oldcap = capacity;
//		capacity = oldcap * 2;
//		cout << "Capacity Doubled old : " << oldcap << " new cap : " << capacity << endl;
//		HashItem<v>* temparr = hashArray;
//		hashArray = new HashItem<v>[capacity];
//		currentElements = 0;
//		for (int i = 0; i < oldcap; i++)
//		{
//			if (temparr[i].status == 2)
//			{
//				cout << "Re-Hashing : ";
//				insert(temparr[i].key, temparr[i].value);
//			}
//		}
//		delete[]temparr;
//	}
//public:
//	HashMap()
//	{
//		currentElements = 0;
//		capacity = 7;
//		hashArray = new HashItem<v>[this->capacity];
//	}
//	HashMap(int cap)
//	{
//		assert(capacity > 1);
//		capacity = cap;
//		currentElements = 0;
//		hashArray = new HashItem<v>[capacity];
//	}
//	void insert(int const key, v const value)
//	{
//		if ((((float)(currentElements)) / ((float)(capacity))) >= 0.75)//load factor
//			doubleCapacity();
//		int index = key%capacity;
//		if (hashArray[index].status == 2)
//		{
//			index = getNextCandidateIndex(key, 1);
//		}
//		hashArray[index].status = 2;
//		hashArray[index].key = key;
//		hashArray[index].value = value;
//		currentElements++;
//		cout << "INSERTED Key : " << key << " Value : " << value <<" index : "<<index<< endl;
//	}
//	bool deleteKey(int const key)
//	{
//		for (int i = 0; i < capacity; i++)
//		{
//			if (hashArray[i].status == 2)
//			{
//				if (hashArray[i].key == key)
//				{
//					hashArray[i].status = 1;
//			//		cout << "Key : " << key << " Deleted" << endl;
//					return true;
//				}
//			}
//		}
//	//	cout << "Not found" << endl;
//		return false;
//	}
//
//	v*get(int const key)
//	{
//		for (int i = 0; i < capacity; i++)
//		{
//			if (hashArray[i].status == 2)
//			{
//				if (hashArray[i].key == key)
//				{
//					return &hashArray[i].value;
//				}
//			}
//		}
//		return NULL;
//	}
//	~HashMap()
//	{
//		delete[]hashArray;
//	}
//};
//template <class v>
//class QHashMap :public HashMap<v>
//{
//public:
//	int getNextCandidateIndex(int key, int i)
//	{
//		int index = (key + (i * i)) % this->capacity;
//		if (this->hashArray[index].status == 0 || this->hashArray[index].status == 1)
//		{
//			return index;
//		}
//		return getNextCandidateIndex(key, ++i);
//	}
//};
//template<class v>
//class DHashMap :public HashMap<v>
//{
//public:
//	int getNextCandidateIndex(int key, int i)
//	{
//		int first_value = (key % this->capacity);
//		int second_value = (7 - (key % 7));
//		int candidate_index = ((first_value + i * second_value) % this->capacity);
//
//		if (this->hashArray[candidate_index].status == 0 || this->hashArray[candidate_index].status == 1)
//		{
//			return candidate_index;
//		}
//		return getNextCandidateIndex(key, ++i);
//	}
//};
//
//void PopulateHash(string filename, HashMap<string>* hash)
//{
//	ifstream file;
//	file.open(filename);
//	if (file.fail())
//	{
//		cout << "Error file not found" << endl;
//		return;
//	}
//	else
//	{
//		cout << "File Loaded SuccessFully" << endl;
//	}
//	string name, line;
//	int id;
//	while (getline(file, line)&&!file.eof())
//	{
//		stringstream linee(line);
//		linee >> id;
//		linee >> name;
//		hash->insert(id, name);
//	}
//}
//int main()
//{
//	HashMap<string>* map;
//	map = new HashMap<string>;
//	PopulateHash("students.txt", map);
//	cout << *map->get(9);
//	map->deleteKey(9);
//    assert(map->get(9) == nullptr);
//	delete map;
//	cout << endl << "-------------------------------------------------------" << endl;
//	map = new QHashMap<string>;
//	PopulateHash("students.txt", map);
//	cout << *map->get(98);
//	map->deleteKey(98);
//	assert(map->get(98) == nullptr);
//	delete map;
//	cout << endl << "-------------------------------------------------------" << endl;
//	map = new DHashMap<string>;
//	PopulateHash("students.txt", map);
//	cout << *map->get(101);
//	map->deleteKey(101);
//	assert(map->get(101) == nullptr);
//	delete map;
//	cout << endl<< "-------------------------------------------------------" << endl;
//
//	cout << "Program Terminated SuccessFully " << endl;
//	system("pause");
//	return 0;
//}