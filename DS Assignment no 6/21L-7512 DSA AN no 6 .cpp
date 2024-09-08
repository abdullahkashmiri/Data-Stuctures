//#include<iostream>
//#include<List>
//#include<fstream>
//#include<string>
//#include<sstream>
//using namespace std;
//
//template<class K, class V>
//class HeapItem
//{
//public:
//	K key;// Private data Members
//	V value;
//	HeapItem()// constructor
//	{
//		key = -1;
//		value = -1;
//	}
//	void setKey(K k)// Setters
//	{
//		key = k;
//	}
//	void setValue(V v)
//	{
//		value = v;
//	}
//};
//template<class K, class V>
//class MinHeap// Min heap Class
//{
//private:
//	//Private Data Members
//	HeapItem<K, V>* minarr;
//	int capacity;
//	int total_items;
//	//Private Functions
//	int parent(int index)
//	{
//		return((index - 1) / 2);
//	}
//	int leftchild(int index)
//	{
//		return ((2 * index) + 1);
//	}
//	int rightchild(int index)
//	{
//		return((2 * index) + 2);
//	}
//	void DoubleCapacity()// Double Capacity Function
//	{
//		cout << "Capacity Doubled" << endl;
//		int original = this->capacity;
//		capacity *= 2;
//		HeapItem<K, V>* temparr = new HeapItem<K, V>[this->capacity];
//		for (int i = 0; i < original; i++)
//		{
//			temparr[i].setKey(minarr[i].key);
//			temparr[i].setValue(minarr[i].value);
//		}
//		delete[] minarr;
//		minarr = temparr;
//	}
//	void ReHeapUp(int index)// Insertion Heaping Up
//	{
//		while (index != 0 && minarr[parent(index)].key > minarr[index].key)
//		{
//			K tempKey = minarr[parent(index)].key;
//			V tempValue = minarr[parent(index)].value;
//			minarr[parent(index)].setKey(minarr[index].key);
//			minarr[parent(index)].setValue(minarr[index].value);
//			minarr[index].setKey(tempKey);
//			minarr[index].setValue(tempValue);
//			index = parent(index);
//		}
//	}
//public:
//	MinHeap()// Default Constructor
//	{
//		this->capacity = 10;
//		this->total_items = 0;
//		this->minarr = new HeapItem<K, V>[this->capacity];
//	}
//	MinHeap(int capacity)// Overloaded constructor
//	{
//		this->capacity = capacity;
//		this->total_items = 0;
//		this->minarr = new HeapItem<K, V>[this->capacity];
//	}
//	void BuildHeap(K key, V value)// Build Heap FUnction AKA INSERTION
//	{
//		if (this->total_items == this->capacity)
//		{
//			cout << "Heap is FULL" << endl;
//			DoubleCapacity();
//		}
//		this->total_items++;
//		int index = total_items - 1;
//		minarr[index].setKey(key);
//		minarr[index].setValue(value);
//		ReHeapUp(index);
//	}
//	void ExtractMin()// Extract min function for extracting minimum i.e at TOP
//	{
//		if (!minarr)
//		{
//			cout << "Empty Heap" << endl;
//			return;
//		}
//		total_items--;
//		minarr[0].setKey(minarr[total_items].key);
//		minarr[0].setValue(minarr[total_items].value);
//		MinHeapify(0);// to get the smallest number at top from heap
//	}
//	void MinHeapify(int index)// Function for bringing min number at top of heap
//	{
//		int left = leftchild(index);
//		int right = rightchild(index);
//		int min = index;
//		if (left < total_items && minarr[left].key < minarr[index].key)// if left is smaller
//		{
//			min = left;
//		}
//		if (right < total_items && minarr[right].key < minarr[min].key)// right is more smaller than left
//		{
//			min = right;
//		}
//		if (min != index)// if child smaller exist 
//		{
//			K tempkey = minarr[index].key;
//			V tempvalue = minarr[index].value;
//			minarr[index].setKey(minarr[min].key);
//			minarr[index].setValue(minarr[min].value);
//			minarr[min].setKey(tempkey);
//			minarr[min].setValue(tempvalue);
//			MinHeapify(min);// swap and recursive call
//		}
//	}
//	int GetMin()// getting min value
//	{
//		if (!is_Empty())
//		{
//			return minarr[0].value;
//		}
//		return NULL;
//	}
//	bool Search(V val)// search function
//	{
//		for (int i = 0; i < total_items; i++)
//		{
//			if (val == minarr[i].value)
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	int getKey(int i)// getting key function
//	{
//		return minarr[i].key;
//	}
//	void Decrease_Key(int id, int weight)// decrease key fun 
//	{
//		for (int i = 0; i < total_items; i++)
//		{
//			if (minarr[i].value == id)
//			{
//				minarr[i].key = weight;
//				MinHeapify(id - 1);
//				return;
//			}
//		}
//	}
//	bool is_Empty()// is empty function
//	{
//		if (total_items == 0)
//		{
//			return true;
//		}
//		return false;
//	}
//	void PrintHeap()// printing heap like array
//	{
//		if (!is_Empty())
//		{
//			int space = 1;
//			for (int i = 0; i < total_items; i++)
//			{
//				if (i == space)
//				{
//					cout << endl;
//					space = 3 * space;
//				}
//				cout << " (" << minarr[i].value << "," << minarr[i].key << ") ";
//			}
//		}
//		cout << endl;
//	}
//
//	~MinHeap()//destructor
//	{
//		delete[]minarr;
//	}
//};
//class GraphNode// Graph node function
//{
//public:
//	int ID = 0;// public data members
//	string location;
//	int weight = 12345;
//	void update(int i, string l, int w)// setter function
//	{
//		ID = i;
//		location = l;
//		weight = w;
//	}
//};
//class Graph :public MinHeap<int, int>// Graph Class 
//{
//private:// Private Data Members
//	MinHeap <int, int> Heap;
//	int total_Vertices;
//	list<pair<GraphNode, int>>* adjList;
//	void Intillizing(GraphNode gn1, GraphNode gn2, int  weight)// Private Initillizing function
//	{
//		adjList[gn1.ID - 1].push_back(make_pair(gn2, weight));
//		adjList[gn2.ID - 1].push_back(make_pair(gn1, weight));
//	}
//public:
//	Graph()// Default constructor
//	{
//		total_Vertices = 0;
//		adjList = NULL;
//		//FileHandeling("file.txt");
//	}
//	void FileHandeling(string filename)// File Handeling Function
//	{
//		ifstream file;
//		file.open(filename);
//		if (file.fail())
//		{
//			cout << "Error File not found" << endl;
//			return;
//		}
//		int Tvertices, id;
//		string location, line, comma;
//		file >> Tvertices;
//		this->total_Vertices = Tvertices;
//		adjList = new list<pair<GraphNode, int>>[total_Vertices];
//		file.ignore();
//		file.ignore();
//		GraphNode gn;
//		for (int i = 0; i < Tvertices; i++)
//		{
//			getline(file, line);
//			stringstream ss(line);
//			ss >> id;
//			ss >> comma;
//			ss >> location;
//			gn.update(id, location, 0);
//			adjList[i].push_back(make_pair(gn, 0));// inserting Vertices
//		}
//		int Tedges, sid, eid, weight;
//		file >> Tedges;
//		file.ignore();
//		file.ignore();
//		for (int i = 0; i < Tedges; i++)
//		{
//			getline(file, line);
//			stringstream ss(line);
//			ss >> sid;
//			ss >> comma;
//			ss >> eid;
//			ss >> weight;// inserting edges
//			Intillizing(adjList[sid - 1].front().first, adjList[eid - 1].front().first, weight);
//		}
//	}
//	void Printing()// Printing Graph function
//	{
//		cout << endl<<"P_R_I_N_T_I_N_G  G_R_A_P_H" << endl;
//		for (int i = 0; i < total_Vertices; i++)
//		{
//			int x = 0;
//			for (auto it : adjList[i])
//			{
//				if (!x)
//					cout << "(" << it.first.ID << "," << it.first.location << "," << it.first.weight << ")   ";
//				else
//					cout << "(" << it.first.ID << "," << it.first.location << "," << it.second << ")   ";
//				x++;
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//	void Logic()// Logic function for Finding Path
//	{
//		cout << endl<<"L_O_G_I_C  F_U_N_C_T_I_O_N" << endl;
//		if (isEmpty())// return if empty
//		{
//			return;
//		}
//		for (int i = 0; i < this->total_Vertices; i++)
//		{
//			if (i == 0)
//				Heap.BuildHeap(0, adjList[i].front().first.ID);// 0 weight for first id
//			else
//				Heap.BuildHeap(12345, adjList[i].front().first.ID);// infinite weight for all other vertices
//		}
//		adjList[0].front().first.weight = 0;// making weight in graph 0
//		Heap.Decrease_Key(0, 0);// making first key weight = 0
//		while (!Heap.is_Empty())// heap has ele
//		{
//			int data = Heap.GetMin();//returning ID
//			int x = 0;
//			for (auto it : adjList[data - 1])// connections with top ele of heap
//			{
//				if (x)// skip vertice only check edge
//				{
//					int id = it.first.ID;
//					if (Heap.Search(id))
//					{
//						if (it.second < Heap.getKey(it.first.ID - 1))
//						{
//							Heap.Decrease_Key(it.first.ID, it.second);
//						}
//					}
//				}
//				x++;// inc
//			}
//			adjList[data - 1].front().first.weight = Heap.getKey(0);
//			Heap.ExtractMin();// delete min
//		}
//		adjList[0].front().first.weight = 0;
//	}
//	void Print_Graph()//Printing Graph Function
//	{
//		cout << "Print Graph" << endl;
//		int data = 0, weight;
//		int data1 = 0;
//		cout << endl;
//		cout << "Total Vertices : " << total_Vertices << endl;
//		cout << "[" << adjList[0].front().first.ID << "] ";
//		cout << "(" << adjList[0].front().first.ID << "," << adjList[0].front().first.location << "," << adjList[0].front().first.weight << ")  ->  ";
//		for (int i = 0; i < total_Vertices; i++)
//		{
//			data = data1;
//			int x = 0;
//			for (auto it : adjList[data])
//			{
//				if (x == 0)
//				{
//					weight = it.first.weight;
//				}
//				else
//				{
//					if (adjList[it.first.ID - 1].front().first.weight == it.second)
//					{
//						cout << "[" << it.first.ID << "] ";
//						cout << "(" << it.first.ID << "," << it.first.location << "," << it.second << ")  ->  ";
//						data1 = it.first.ID;
//						data1--;
//						break;
//					}
//				}
//				x++;
//			}
//		}
//	}
//	void Print_Path()// Print Path wrap function
//	{
//		cout << endl << "PRINTING OF PATH " << endl;
//		int a = 0;
//		list<int>* visit = new list<int>[1];
//		Print_GraphR(0, a, visit);
//	}
//	void Print_GraphR(int data, int& count, list <int>* visit)// print path recursive function
//	{
//		int weight;
//		bool flag = false;
//		int old_id, old_weight;
//		string old_loc;
//		if (!count)
//		{
//			count++;
//			cout << "Total Vertices : " << total_Vertices << endl;
//			//	cout << "(" << adjList[data].front().first.ID << "," << adjList[data].front().first.location << "," << adjList[data].front().first.weight << ")"<<endl;
//			visit[0].push_back(adjList[data].front().first.ID);
//		}
//		if (count < total_Vertices)
//		{
//			int x = 0;
//			for (auto it : adjList[data])
//			{
//				if (x == 0)
//				{
//					old_id = it.first.ID;// storing previous node data
//					old_loc = it.first.location;
//					old_weight = it.first.weight;
//					weight = it.first.weight;
//				}
//				else
//				{
//					if (adjList[it.first.ID - 1].front().first.weight == it.second)
//					{
//						flag = false;
//						for (auto iu : visit[0])// if ele is not visited of printed
//						{
//							if (iu == it.first.ID)
//								flag = true;
//						}
//						if (!flag)
//						{
//							cout << "(" << old_id << "," << old_loc << "," << old_weight << ") -->> ";
//							cout << "(" << it.first.ID << "," << it.first.location << "," << it.second << ")" << endl;
//							data = it.first.ID;
//							count++;
//							visit[0].push_back(it.first.ID);
//							data--;
//							Print_GraphR(data, count, visit);
//						}
//					}
//				}
//				x++;
//			}
//		}
//	}
//	int getTotalvertices()
//	{
//		return total_Vertices;
//	}
//	void save_file(string filename)// Saving Graph Function
//	{
//		ofstream MyFile(filename);// Create file
//		for (int i = 0; i < total_Vertices; i++)
//		{
//			int x = 0;
//			for (auto it : adjList[i])
//			{
//				if (!x)
//					MyFile << "(" << it.first.ID << "," << it.first.location << "," << it.first.weight << ") ->  ";
//				else
//					MyFile << "(" << it.first.ID << "," << it.first.location << "," << it.second << ")   ";
//				x++;
//			}
//			MyFile << endl;
//		}
//		MyFile.close();//close file
//	}
//	bool isEmpty()// is empty function
//	{
//		if (total_Vertices != 0)
//			return false;
//		return true;
//	}
//	void Input_From_File(string filename)// taking input from file
//	{
//		cout << "Taking Input from File" << endl;
//		FileHandeling(filename);
//	}
//	bool Add_Vertex(int id, string loc)// adding vertex function
//	{
//		for (int i = 0; i < total_Vertices; i++)
//		{
//			if (adjList[i].front().first.ID == id)
//			{
//				cout << "INVALID INPUTS" << endl;
//				return false;
//			}
//		}
//		cout << "Adding Vertex ID : " << id << " Location : " << loc << endl;
//		total_Vertices++;
//		list<pair<GraphNode, int>>* tempadjList;
//		tempadjList = new list<pair<GraphNode, int>>[total_Vertices];
//		for (int i = 0; i < total_Vertices - 1; i++)
//		{
//			for (auto it : adjList[i])
//			{
//				tempadjList[i].push_back(make_pair(it.first, it.second));
//			}
//		}
//		GraphNode gn;
//		gn.update(id, loc, 0);
//		tempadjList[total_Vertices - 1].push_back(make_pair(gn, 0));
//		delete[]adjList;
//		adjList = tempadjList;
//		return true;
//	}
//	bool Edge(int sid, int eid, int weight)// adding edge function
//	{
//		if (sid == eid)
//		{
//			cout << "INVALID INPUTS" << endl;
//			return false;
//		}
//	bool fsid = false, feid = false;
//		for (int i = 0; i < total_Vertices; i++)
//		{
//			if (adjList[i].front().first.ID == sid)
//			{
//				fsid = true;
//			}
//			else if (adjList[i].front().first.ID == eid)
//			{
//				feid = true;
//			}
//		}
//		if (fsid && feid)
//		{
//			cout << "Adding Edge Starting ID : " << sid << " Ending ID : " << eid << " Weight in B/W : " << weight << endl;
//			Intillizing(adjList[sid - 1].front().first, adjList[eid - 1].front().first, weight);
//			return true;
//		}
//		else 
//		{
//			cout << "INVALID INPUTS" << endl;
//			return false;
//		}
//	}
//};
//void Print_Content()
//{
//	cout << "-------------[M_E_N_U]-------------" << endl;
//	cout << "[1] -> INPUT A GRAPH FROM FILE" << endl;
//	cout << "[2] -> SAVE A GRAPH IN FILE" << endl;
//	cout << "[3] -> ADD A VERTEX IN EXISTING GRAPH G" << endl;
//	cout << "[4] -> ADD AN EDGE IN EXISTING GRAPH" << endl;
//	cout << "[5] -> PRINT PATH [FLAN] OF GRAPH" << endl;
//	cout << "[6] -> PRINT COMPLETE GRAPH" << endl;
//	cout << "[7] -> APPLY FIND PATH ALGORITHM ON GRAPH" << endl;
//	cout << "[0] -> TO EXIT" << endl;
//	cout << "Enter Here :- ";
//}
//int main()
//{
//	Graph G;
//	bool live = true;
//	int option;
//	while (live)
//	{
//		Print_Content();
//		cin >> option;
//		system("cls");
//		if (option == 1)
//		{
//			cout << "FECTING GRAPH FROM FILE [file.txt] " << endl;
//			G.Input_From_File("file.txt");
//		}
//		else if (option == 2)
//		{
//			cout << "SAVING GRAPH IN FILE [outputgraph.txt]" << endl;
//			G.save_file("outputfile.txt");
//		}
//		else if (option == 3)
//		{
//			int vertex;
//			string loc;
//			cout << "ADDING A VERTEX IN GRAPH" << endl;
//			vertex = G.getTotalvertices();
//			vertex++;
//			cout << "Enter Location : ";
//			cin >> loc;
//			G.Add_Vertex(vertex, loc);
//			cout << "ADDING A EDGE IN GRAPH" << endl;
//			int eid, weight;
//			cout << "Enter Ending index of Edge : ";
//			cin >> eid;
//			cout << "Enter Weight Between Edge : ";
//			cin >> weight;
//			while (weight < 1)
//			{
//				cout << "Invalid weight : ";
//				cin >> weight;
//			}
//			G.Edge(vertex, eid, weight);
//		}
//		else if (option == 4)
//		{
//			int sid, eid, weight;
//			cout << "ADDING A EDGE IN GRAPH" << endl;
//			cout << "Enter Starting index of Edge : ";
//			cin >> sid;
//			cout << "Enter Ending index of Edge : ";
//			cin >> eid;
//			cout << "Enter Weight Between Edge : ";
//			cin >> weight;
//			while (weight < 1)
//			{
//				cout << "Invalid weight : ";
//				cin >> weight;
//			}
//			G.Edge(sid, eid, weight);
//		}
//		else if (option == 5)
//		{
//			cout << "PRINTING PATH OF FLAN GRAPH" << endl;
//			G.Print_Path();
//		}
//		else if (option == 6)
//		{
//			cout << "PRINTING COMPLETE GRAPH" << endl;
//			G.Printing();
//		}
//		else if (option == 7)
//		{
//			cout << "APPLYING LOGIC ON GRAPH" << endl;
//			G.Logic();
//		}
//		else if (option == 0)
//		{
//			live = false;
//			cout << "PROGRAM SUCCESSFULLY EXITED" << endl;
//		}
//	}
//	cout << endl << "Program Terminated SuccessFully" << endl;//
//	return 0;
//}