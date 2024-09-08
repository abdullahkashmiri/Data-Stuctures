//
///*Implement a class called myVector that stores integers in it. You have to implement the
//following members:
//1. Private data member arrayPtr to integer array
//2. Private data member capacity of array
//3. Private data member that specifies the actual elements i.e.current size(elements added to
//the array by the user (initially it should be set to zero))
//4. Default constructor (initially it should allocate an array of size 2. You will have to set the
//other private members too. Initialize the array to zero)
//5. Constructor with int parameter (the int parameter specifies the capacity of the array). The
//constructor should initialize the entire array to zero.
//6. Copy constructor (should make a deep copy)
//7. Destructor (if the array is allocated then deallocate it)
//8. Get function for total capacity…(think of other get functions)
//9. + operator that takes an integer variable as parameter. This method should add one
//integer to the array and increase the number of current elements. If the allocated size is
//not sufficient then increase the capacity of the array by double. Copy the old array in the
//new one (including the new element) and delete the old array. b=
//10. – operator that takes no parameters. This method should delete the last added value from
//the array and change the current size. (note no memory allocation or deallocation will
//take place here)
//11. + operator that takes any Vector object as argument. What should be the exact type of
//that parameter? This operator should return a new array which has all the elements of the
//current object (lhs) and the array passed as parameter (rhs).
//12. = operator which should make a deep copy. Make sure if lval is already allocated then it
//should be deallocated and allocated again with the size of the rval
//13. [] operator which should place the value of an element at index in the parameter. If the
//index is out of bound then return false otherwise return true.
//14. &gt;&gt;operator which takes as input the elements of myVector.
//15. &lt;&lt;operator which prints the elements of myVector.
//Provide a sufficient main program that tests all of the above functions. (including destructors
//too).*/
//
//#include<iostream>
//using namespace std;
//
//class myVector
//{
//private:
//	int *arrayptr;
//	int capacity;
//	int csize;
//public:
//	myVector()//default constructor
//	{
//		this->capacity = 2;
//		this->csize = 0;
//		this->arrayptr = new int[this->capacity];
//		for (int i = 0; i < this->capacity; i++)
//		{
//			this->arrayptr[i] = 0;
//		}
//	}
//	myVector(int givenCap)//overloaded constructor
//	{
//		this->capacity = givenCap;
//		this->csize = 0;
//		this->arrayptr = new int[this->capacity];
//		for (int i = 0; i < this->capacity; i++)
//		{
//			this->arrayptr[i] = 0;
//		}
//	}
//	myVector(const myVector &dummy)//copy constructor
//	{
//		this->capacity = dummy.capacity;
//		this->csize = dummy.csize;
//		//	delete []this->arrayptr;
//		this->arrayptr = new int[this->capacity];
//		for (int i = 0; i < this->capacity; i++)
//		{
//			this->arrayptr[i] = dummy.arrayptr[i];
//		}
//	}
//	int getCapacity()//Getter for capacity
//	{
//		return this->capacity;
//	}
//	myVector operator + (int a)//+Operator for add elements
//	{
//		if (this->csize < this->capacity)
//		{
//			this->arrayptr[this->csize] = a;
//			this->csize++;
//		}
//		else if (this->csize == this->capacity)
//		{
//			myVector temp;
//			temp.capacity = this->capacity * 2;
//			temp.arrayptr = new int[temp.capacity];
//			for (int i = 0; i < temp.capacity; i++)
//			{
//				if (i < this->csize)
//				{
//					temp.arrayptr[i] = this->arrayptr[i];
//					temp.csize++;
//				}
//				else if (i == this->csize)
//				{
//					temp.arrayptr[i] = a;
//					temp.csize++;
//				}
//				else
//				{
//					temp.arrayptr[i] = 0;
//				}
//			}
//				delete []arrayptr;
//			cout << "temp" << endl;
//			return temp;
//		}
//		return *this;
//	}
//	void operator--()//-operator for deleting elements
//	{
//		this->arrayptr[csize] = 0;
//		csize--;
//	}
//	myVector operator+(const myVector& a)//Lhs and rhs +Operator
//	{
//		myVector temp;
//		temp.capacity = this->capacity + a.capacity;
//		temp.csize = csize;
//		temp.arrayptr = new int[temp.capacity];
//		for (int i = 0; i <temp.capacity; i++)
//		{
//			if (i < this->csize)
//			{
//				temp.arrayptr[i] = this->arrayptr[i];
//				
//			}
//			else 
//			{
//				temp.arrayptr[i] = a.arrayptr[i-csize];
//				temp.csize++;
//			}
//			//else
//			//	temp.arrayptr[i] = 0;
//		}
//		return temp;
//	}
//	bool operator[](int index)//Checking index
//	{
//		if (index > 0 && index < capacity)
//			return true;
//		return false;
//	}
//
//	friend ostream& operator<<(ostream &op, const myVector &v)//Printing fun
//	{
//		op << "The Capacity of Array is : " << v.capacity << endl;
//		op << "The Current Size of Array is : " << v.csize << endl;
//		cout << "Array is : ";
//		for (int i = 0; i < v.csize; i++)
//		{
//			op << v.arrayptr[i] << ",";
//		}
//		return op;
//	}
//	friend istream& operator>>(istream& ip, myVector &v)//input function
//	{
//		cout << "Enter the capacity of Array : " << endl;
//		ip >> v.capacity;
//		v.csize = 0;
//		v.arrayptr = new int[v.capacity];
//		cout << "Enter the elements in the Array : " << endl;
//		for (int i = 0; i < v.capacity; i++)
//		{
//			ip >> v.arrayptr[i];
//			v.csize++;
//		}
//		return ip;
//	}
//
//	void operator=(myVector &v)
//	{
//		delete this->arrayptr;
//		this->capacity = v.capacity;
//		this->csize = v.csize;
//		this->arrayptr = new int[this->capacity];
//		for (int i = 0; i < this->capacity; i++)
//		{
//			this->arrayptr[i] = v.arrayptr[i];
//		}
//	}
//
//	~myVector()
//	{
//	if (capacity>0)
//	{
//	delete[] arrayptr;
//	}
//	}
//};
//
//int main()
//{
//	myVector v1, v2, v3;
//
//	int i = 0, check, val;
//	while (i == 0)
//	{
//		cout << "Enter Key : " << endl;
//		cout << "\n1 add integer\n2 add object\n3check capacity\n4delete integer\n5deep copy\6 check index\n" << endl;
//		cin >> check;
//		if (check == 1)
//		{
//			cout << "Enter Array : " << endl;
//			cin >> v1;
//			cout << "Enter value";
//			cin >> val;
//			v2 = v1 + val;
//			cout << v2;
//		}
//		else if (check == 2)
//		{
//			cout << "Enter Array 1: " << endl;
//			cin >> v1;
//			cout << "Enter Array 2: " << endl;
//			cin >> v2;
//			v3 = v1 + v2;
//			cout << v3;
//		}
//		else if (check == 3)
//		{
//			cout << "Enter array : ";
//			cin >> v1;
//			cout << "Capacity is : " << v1.getCapacity();
//		}
//		else if (check == 4)
//		{
//			cout << "Enter Array 1: " << endl;
//			cin >> v1;
//			--v1;
//			cout << v1;
//		}
//		else if (check == 5)
//		{
//			cout << "Enter array : ";
//			cin >> v1;
//			cout << v1;
//			v2 = v1;
//			cout << v2;
//		}
//		else if (check == 6)
//		{
//			cout << "Enter array : ";
//			cin >> v1;
//			cout << "enter index: ";
//			cin >> val;
//			if (v1[val] == true)
//				cout << "yes index avalaible" << endl;
//			else
//				cout << " index not avaliable" << endl;
//		}
//	}
//
//
//
//
//	cout << endl << "Program Completed Successfully" << endl;
//	system("pause");
//	return 0;
//}