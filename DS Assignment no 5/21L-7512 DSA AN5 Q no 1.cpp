#include<iostream>
using namespace std;

class Interval_Heap
{
private:
	//Private Data Members
	int** HeapArr;
	int Capacity;
	int currentSize;
	//Private Functions
	int parent(int index)//getting parent index
	{
		return((index - 1) / 2);
	}
	int leftchild(int index)//getting leftchild index
	{
		return ((2 * index) + 1);
	}
	int rightchild(int index)//getting right child index
	{
		return ((2 * index) + 2);
	}
	void Double_capacity()// double capcaity function
	{
		cout << "Double Capacity!!" << endl;
		int oldcapacity = Capacity;
		Capacity = 2 * Capacity;
		int** tempArr = HeapArr;
		HeapArr = new int* [2];
		HeapArr[0] = new int[Capacity];
		HeapArr[1] = new int[Capacity];
		for (int i = 0; i <= oldcapacity; i++)
		{
			HeapArr[0][i] = tempArr[0][i];
			HeapArr[1][i] = tempArr[1][i];
		}
		delete[]tempArr[0];
		delete[]tempArr[1];
		delete[]tempArr;
		cout << "Old Capacity : " << oldcapacity << "  Current Capacity : " << Capacity << endl;
	}
public:
	Interval_Heap()//Default Constuctor
	{
		Capacity = 10;
		currentSize = 0;
		HeapArr = new int* [2];
		HeapArr[0] = new int[Capacity];
		HeapArr[1] = new int[Capacity];
	}
	Interval_Heap(int cap)//Overloaded Constructor
	{
		Capacity = cap;
		currentSize = 0;
		HeapArr = new int* [2];
		HeapArr[0] = new int[Capacity];
		HeapArr[1] = new int[Capacity];
	}
	void insert(int data)//insertion data 
	{
		//	cout << "Data inputed : " << data << endl;
		if (currentSize == (Capacity * 2))// if heap gets full
		{
			cout << "Heap is Full" << endl;
			Double_capacity();
			//return;
		}
		int index = (currentSize / 2);
		bool flag;
		if (currentSize % 2 == 0)
			flag = true;//new node to be created
		else
			flag = false;// no new node to be created
		if (flag)	//new node [even elements]
		{
			if (!index)//root node
			{
				HeapArr[0][index] = data;
			}
			else
			{
				int parentI = parent(index);
				if (data >= HeapArr[0][parentI] && data <= HeapArr[1][parentI])//between parent closed interval
				{
					HeapArr[0][index] = data;
				}
				else if (data < HeapArr[0][parentI])//data less than parent left ele
				{
					HeapArr[0][index] = data;
					MinHeapUp(index);
				}
				else if (data > HeapArr[1][parentI])//data greater than parent right ele
				{
					HeapArr[1][index] = data;
					MaxHeapUp(index);
					HeapArr[0][index] = HeapArr[1][index];
				}
			}
		}
		else
		{
			if (HeapArr[0][index] < data)// data greater than left ele
			{
				HeapArr[1][index] = data;
			}
			else
			{
				HeapArr[1][index] = HeapArr[0][index];//swapping
				HeapArr[0][index] = data;
			}
			MinHeapUp(index);
			MaxHeapUp(index);
		}
		currentSize++;
	}

	void MinHeapUp(int index)// min heap up function
	{
		while (index && (HeapArr[0][parent(index)] > HeapArr[0][index]))// putting smallest to top
		{
			int temp = HeapArr[0][index];
			HeapArr[0][index] = HeapArr[0][parent(index)];
			HeapArr[0][parent(index)] = temp;
			index = parent(index);
		}
	}

	void MaxHeapUp(int index)// max heap up function
	{
		while (index && (HeapArr[1][parent(index)] < HeapArr[1][index]))// putting max to top
		{
			int temp = HeapArr[1][index];
			HeapArr[1][index] = HeapArr[1][parent(index)];
			HeapArr[1][parent(index)] = temp;
			index = parent(index);
		}
	}
	void Print()// printing ike bst
	{
		if (!is_Empty())
		{
			int space = currentSize / 4;
			bool flag = true;
			cout << endl << "Printing Heap" << endl;
			for (int i = 0, j = 0, k = 0; j < currentSize; i++)
			{
				if (flag)
				{
					for (int l = 0; l < space; l++)
						cout << "\t";
					if (!i)
						cout << "\t";
					space--;
					flag = false;
				}
				cout << "(" << HeapArr[0][i];
				j++;
				if (j < currentSize)
				{
					cout << " , " << HeapArr[1][i] << ")";
					for (int l = 0; l <= space; l++)
						cout << "\t";
					j++;
				}
				else
					cout << ")" << endl;
				if (k == i)
				{
					cout << endl;
					k = (i + 1) * 2;
					flag = true;
				}
			}
			cout << endl;
		}
		else cout << "Empty Heap" << endl;
	}
	bool is_Empty()// if heap is empty
	{
		if (!currentSize)
			return true;
		return false;
	}
	//Delete Function 
	void delete_(int data)// delete data function
	{
		//	cout << "Data Input For Deletion : " << data << endl;
		if (!is_Empty())
		{
			bool flag = false;
			for (int i = 0; i <= currentSize / 2; i++)
			{
				if (HeapArr[0][i] == data)// data found at left ele
				{
					int index;
					if (currentSize % 2 == 0)//Even elemnts
						index = (currentSize / 2) - 1;
					else
						index = (currentSize / 2);
					HeapArr[0][i] = HeapArr[0][index];// placing left last ele to deleted one 
					if (currentSize % 2 == 0)//placing right elemnet to left
					{
						HeapArr[0][index] = HeapArr[1][index];
					}
					currentSize--;// size--
					int check = i;
					MinReHeapDown(i, check);// getting smallest from th ebottom to there
					if (HeapArr[0][check] > HeapArr[1][check])// if interval is opposite then swapp and do heap up
					{
						int temp = HeapArr[0][check];
						HeapArr[0][check] = HeapArr[1][check];
						HeapArr[1][check] = temp;
						MinHeapUp(check);
						MaxHeapUp(check);
					}
					flag = true;
					break;
				}
				else if (HeapArr[1][i] == data)// data found at right ele
				{
					int index;
					if (currentSize % 2 == 0)//even no of elements
						index = (currentSize / 2) - 1;
					else
						index = currentSize / 2;// odd no of elements
					if (currentSize % 2 == 0)// place right last ele if even 
						HeapArr[1][i] = HeapArr[1][index];
					else
						HeapArr[1][i] = HeapArr[0][index];
					currentSize--;
					int check = index;
					MaxReHeapDown(i, check);// if interval is swapped then swap and sort
					if (HeapArr[0][check] > HeapArr[1][check])
					{
						int temp = HeapArr[0][check];
						HeapArr[0][check] = HeapArr[1][check];
						HeapArr[1][check] = temp;
						MinHeapUp(check);
						MaxHeapUp(check);
					}
					flag = true;
					break;
				}
			}
			if (flag)
			{
				cout << "Data Deleted : " << data << endl;
			}
			else
				cout << "Data Not Found : " << endl;
		}
		else// empty heap
		{
			cout << "Empty Heap" << endl;
		}
	}
	void MinReHeapDown(int index, int& check)// min heap down function
	{
		if (index < currentSize / 2)
		{
			int left = leftchild(index);// left child
			int right = rightchild(index);//right child
			int min = index;
			if (left < currentSize / 2 && (HeapArr[0][left] < HeapArr[0][index]))// if left is maller
			{
				min = left;
				check = min;
			}
			if (right < currentSize / 2 && (HeapArr[0][right] < HeapArr[0][min]))//if right is smaller than left
			{
				min = right;
				check = min;
			}
			if (index != min)// if any smaller index found at child
			{
				int temp = HeapArr[0][index];//swap and recusrive call
				HeapArr[0][index] = HeapArr[0][min];
				HeapArr[0][min] = temp;
				MinReHeapDown(min, check);
			}
		}
	}
	void MaxReHeapDown(int index, int& check)// max heap down function
	{
		if (index < currentSize / 2)
		{
			int left = leftchild(index);//left child 
			int right = rightchild(index);//right child
			int max = index;
			if (left < currentSize / 2 && (HeapArr[1][left] > HeapArr[1][index]))// if left child is greater
			{
				max = left;
				check = left;
			}
			if (right < currentSize / 2 && (HeapArr[1][right] > HeapArr[1][max]))// if right chiild is grater than left
			{
				max = right;
				check = right;
			}
			if (index != max)// if any greater index found then swap and recursive call
			{
				int temp = HeapArr[1][index];
				HeapArr[1][index] = HeapArr[1][max];
				HeapArr[1][max] = temp;
				MaxReHeapDown(max, check);
			}
		}
	}
	void update(int olddata, int newdata)// update function
	{
		if (olddata == newdata)// both data are equal
			return;
		if (currentSize % 2 == 0) //even elements
		{
			for (int i = 0; i < currentSize / 2; i++)// loop should be one less
			{
				if (HeapArr[0][i] == olddata)// old data found at left child     
				{
					//				cout << "Old data found at " << i << endl;
					HeapArr[0][i] = newdata;// placing new data in place of old data
					if (HeapArr[0][i] > HeapArr[1][i])// if left child is greater than right child
					{
						int temp = HeapArr[0][i];//swap
						HeapArr[0][i] = HeapArr[1][i];
						HeapArr[1][i] = temp;
						MaxHeapUp(i);
						int check = i;
						MinReHeapDown(i, check);
						if (HeapArr[0][check] > HeapArr[1][check])
						{
							int temp = HeapArr[0][check];
							HeapArr[0][check] = HeapArr[1][check];
							HeapArr[1][check] = temp;
							MinHeapUp(check);
							MaxHeapUp(check);
						}
					}
					else// no swapping as left ele is smaller than right ele
					{
						if (olddata < newdata || newdata == HeapArr[1][i])//new data is greater than left child or new data == right ele
						{
							int check = i;
							MinReHeapDown(i, check);//bring min from bottom to there
							//						cout << "Check condition" << endl;
							if (HeapArr[0][check] > HeapArr[1][check])
							{
								int temp = HeapArr[0][check];
								HeapArr[0][check] = HeapArr[1][check];
								HeapArr[1][check] = temp;
								MinHeapUp(check);
								MaxHeapUp(check);
							}
						}
						else if (olddata > newdata)// new data is less than old data
						{
							//				Print();
							MinHeapUp(i);//bring the min to the top
							//							cout << "NO Check condition" << endl;
						}
					}
					break;
				}
				else if (HeapArr[1][i] == olddata)// old data found at right child
				{
					//					cout << "Old Data found at : " << i << endl;
					HeapArr[1][i] = newdata;//placing new data at right child
					if (HeapArr[0][i] > HeapArr[1][i])
					{
						//					cout << "Swapped " << endl;
						int temp = HeapArr[0][i];//swap
						HeapArr[0][i] = HeapArr[1][i];
						HeapArr[1][i] = temp;
						MinHeapUp(i);
						int check = i;
						MaxReHeapDown(i, check);
						if (HeapArr[0][check] > HeapArr[1][check])
						{
							temp = HeapArr[0][check];
							HeapArr[0][check] = HeapArr[1][check];
							HeapArr[1][check] = temp;
							MinHeapUp(check);
							MaxHeapUp(check);
						}
					}
					else // no swapping as left is smaller than right
					{
						//					cout << "Else of right ele" << endl;
						if (olddata < newdata)
						{
							//						cout << "Old right is smaller than new right" << endl;
							MaxHeapUp(i);
						}
						else if (olddata > newdata)
						{
							int check = i;
							MaxReHeapDown(i, check);
							if (HeapArr[0][check] > HeapArr[1][check])
							{
								int temp = HeapArr[0][check];
								HeapArr[0][check] = HeapArr[1][check];
								HeapArr[1][check] = temp;
								MinHeapUp(check);
								MaxHeapUp(check);
							}
						}
					}
					break;
				}
			}
		}
		else// odd elements
		{
			for (int i = 0; i <= currentSize / 2; i++)// loop should be equal 
			{
				if (HeapArr[0][i] == olddata)// old data found at left child     
				{
					//					cout << "Old data found at " << i << endl;
					HeapArr[0][i] = newdata;// placing new data in place of old data
					if (i == currentSize / 2)
					{
						currentSize--;
						insert(newdata);
						break;
					}
					if (HeapArr[0][i] > HeapArr[1][i])// if left child is greater than right child
					{
						//					cout << "swapped" << endl;
						int temp = HeapArr[0][i];//swap
						HeapArr[0][i] = HeapArr[1][i];
						HeapArr[1][i] = temp;
						MaxHeapUp(i);
						int check = i;
						MinReHeapDown(i, check);
						if (HeapArr[0][check] > HeapArr[1][check])
						{
							int temp = HeapArr[0][check];
							HeapArr[0][check] = HeapArr[1][check];
							HeapArr[1][check] = temp;
							MinHeapUp(check);
							MaxHeapUp(check);
						}
					}
					else// no swapping as left ele is smaller than right ele
					{
						if (olddata < newdata || newdata == HeapArr[1][i])//new data is greater than left child or new data == right ele
						{
							int check = i;
							MinReHeapDown(i, check);//bring min from bottom to there
							//						cout << "Check condition" << endl;
							if (HeapArr[0][check] > HeapArr[1][check])
							{
								int temp = HeapArr[0][check];
								HeapArr[0][check] = HeapArr[1][check];
								HeapArr[1][check] = temp;
								MinHeapUp(check);
								MaxHeapUp(check);
							}
						}
						else if (olddata > newdata)// new data is less than old data
						{
							//						Print();
							MinHeapUp(i);//bring the min to the top
							//						cout << "NO Check condition" << endl;
						}
					}
					break;
				}
				else if (HeapArr[1][i] == olddata && i < currentSize / 2)// old data found at right child
				{
					//			cout << "Old Data found at : " << i << endl;
					HeapArr[1][i] = newdata;//placing new data at right child
					if (HeapArr[0][i] > HeapArr[1][i])
					{
						//			cout << "Swapped " << endl;
						int temp = HeapArr[0][i];//swap
						HeapArr[0][i] = HeapArr[1][i];
						HeapArr[1][i] = temp;
						//				Print();
						MinHeapUp(i);
						int check = i;
						//			Print();
						MaxReHeapDown(i, check);
						if (HeapArr[0][check] > HeapArr[1][check])
						{
							temp = HeapArr[0][check];
							HeapArr[0][check] = HeapArr[1][check];
							HeapArr[1][check] = temp;
							MinHeapUp(check);
							MaxHeapUp(check);
						}
					}
					else // no swapping as left is smaller than right
					{
						//			cout << "Else of right ele" << endl;
						if (olddata < newdata)
						{
							//				cout << "Old right is smaller than new right" << endl;
							MaxHeapUp(i);
							//		Print();
						}
						else if (olddata > newdata)
						{
							int check = i;
							MaxReHeapDown(i, check);
							if (HeapArr[0][check] > HeapArr[1][check])
							{
								int temp = HeapArr[0][check];
								HeapArr[0][check] = HeapArr[1][check];
								HeapArr[1][check] = temp;
								MinHeapUp(check);
								MaxHeapUp(check);
							}
						}
					}
					break;
				}
			}
		}
	}
	void PrintHeap()// printing heap like array
	{
		if (!is_Empty())
		{
			int space = 2;
			for (int i = 0; i < currentSize / 2; i++)
			{
				cout << "(" << HeapArr[0][i] << "," << HeapArr[1][i] << ")\t";
				if (i == 0)
					cout << endl;
				if (space == i)
				{
					space = 3 * space;
					cout << endl;
				}
			}
			if (currentSize % 2 != 0)
			{
				cout << "(" << HeapArr[0][currentSize / 2] << ")" << endl;
			}
		}
		cout << endl;
	}
	~Interval_Heap()// desturctor
	{
		delete[]HeapArr[0];
		delete[]HeapArr[1];
		delete[]HeapArr;
	}
};
void PrintContent()// printing main-interface content
{
	cout << "\nINTERVAL HEAP" << endl;
	cout << "[1] -> INSERT" << endl;
	cout << "[2] -> DELETE" << endl;
	cout << "[3] -> UPDATE" << endl;
	cout << "[4] -> PRINT" << endl;
	cout << "[0] -> EXIT" << endl;
	cout << "Enter Here : ";
}
int main()
{

	Interval_Heap IH;
	int data = 10, digits = 0;

	IH.insert(2);
	IH.insert(30);
	IH.insert(3);
	IH.insert(17);
	IH.insert(4);
	IH.insert(15);
	IH.insert(4);
	IH.insert(12);
	IH.insert(3);
	IH.insert(11);
	IH.insert(5);
	IH.insert(10);
	IH.insert(6);
	IH.insert(15);
	IH.insert(4);
	IH.insert(10);
	IH.insert(5);
	IH.insert(11);
	IH.insert(5);
	IH.insert(9);
	IH.insert(4);
	IH.insert(7);
	IH.insert(8);
	IH.insert(8);
	IH.insert(7);
	IH.insert(9);

	while (data)
	{
		//	IH.Print();
		cout << "INTERVAL-HEAP AFTER INSTRUCTION" << endl;
		IH.PrintHeap();
		PrintContent();
		cin >> data;
		if (data == 1)
		{
			//	cout << "How Many Digits you want to insert : ";
			//	cin >> digits;
			//	for (int i = 0; i < digits; i++)
			//	{
			//	cout << "Enter " << i + 1 << " data : ";
			cout << "Enter data : ";
			cin >> data;
			system("cls");
			cout << "INTERVAL-HEAP BEFORE INSTRUCTION" << endl;
			IH.PrintHeap();
			IH.insert(data);
			//IH.Print();
	//	}
			data = 1;
		}
		else if (data == 2)
		{
			cout << "Enter data to delete : ";
			cin >> data;
			system("cls");
			cout << "INTERVAL-HEAP BEFORE INSTRUCTION" << endl;
			IH.PrintHeap();
			IH.delete_(data);
			data = 2;
		}
		else if (data == 3)
		{
			cout << "Enter Old Data : ";
			cin >> data;
			cout << "Enter new Data : ";
			cin >> digits;
			//		IH.Print();
			system("cls");
			cout << "INTERVAL-HEAP BEFORE INSTRUCTION" << endl;
			IH.PrintHeap();
			IH.update(data, digits);
			data = 3;
		}
		else if (data == 4)
		{
			IH.PrintHeap();
		}
	}

	cout << endl << "Program Terminted SuccessFully" << endl;
	system("pause");
	return 0;
}