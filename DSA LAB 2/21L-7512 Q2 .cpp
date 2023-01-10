////Question 2:
////Convert the class myVector, which is implemented in Question 1,
////in a generic template class that can store any data value in it.
//
//
//#include<iostream>
//using namespace std;
//
//template <class T>
//class myVector
//{
//private:
//    T *arrayptr;
//	int capacity;
//	int csize;
//public:
//	myVector()//default constructor
//	{
//		this->capacity = 2;
//		this->csize = 0;
//		this->arrayptr = new T[this->capacity];
//		for (int i = 0; i < this->capacity; i++)
//		{
//			this->arrayptr[i] = 0;
//		}
//	}
//	myVector(int givenCap)//overloaded constructor
//	{
//		this->capacity = givenCap;
//		this->csize = 0;
//		this->arrayptr = new T[this->capacity];
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
//		this->arrayptr = new T[this->capacity];
//		for (int i = 0; i < this->capacity; i++)
//		{
//			this->arrayptr[i] = dummy.arrayptr[i];
//		}
//	}
//	int getCapacity()//Getter for capacity
//	{
//		return this->capacity;
//	}
//	void operator + (T a)//+Operator for add elements
//	{
//		int check = 0;
//		if (this->csize < this->capacity)
//		{
//			this->arrayptr[this->csize] = a;
//			this->csize++;
//		}
//		else if (this->csize == this->capacity)
//		{
//			myVector temp;
//			temp.capacity = this->capacity * 2;
//			temp.arrayptr = new T[temp.capacity];
//			temp.csize = 0;
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
//			//cout << "temp" << endl;
//				check = 1;
//			cout << temp;
//			
//		}
//		if (check == 0)
//		{
//			cout << this;
//		}
//	}
//	void operator--()//-operator for deleting elements
//	{
//		this->arrayptr[csize] = 0;
//		csize--;
//	}
//	void operator+(const myVector& a)//Lhs and rhs +Operator
//	{
//		myVector temp;
//		temp.capacity = this->capacity + a.capacity;
//		temp.csize = csize;
//		temp.arrayptr = new T[temp.capacity];
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
//		cout <<temp;
//	}
//	bool operator[](T index)//Checking index
//	{
//		if (index > 0 && index < capacity)
//		{
//			cout << "Avaliable boss" << endl;
//			int val;
//			cout << "Enter value that you want to replace : ";
//			cin >> val;
//			this->arrayptr[index] = val;
//			return true;
//		}
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
//		v.arrayptr = new T[v.capacity];
//		cout << "Enter the elements in the Array : " << endl;
//		for (int i = 0; i < v.capacity; i++)
//		{
//			ip >> v.arrayptr[i];
//			v.csize++;
//		}
//		return ip;
//	}
//
//	void operator = (myVector &v)
//	{
//		delete this->arrayptr;
//		this->capacity = v.capacity;
//		this->csize = v.csize;
//		this->arrayptr = new T[this->capacity];
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
//	myVector <int>v1, v2, v3;
//	int i = 0, check, val;
//	while (i == 0)
//	{
//		cout << "\n-----------------------------------------------------------------------------\nEnter Key : " << endl;
//		cout << "\n1 add integer\n2 add object\n3 check capacity\n4 delete integer\n5 deep copy\n6 check index\n" << endl;
//		cin >> check;
//		if (check == 1)
//		{
//			cin >> v1;
//			cout << "Enter value ";
//			cin >> val;
//			v1 + val;
//			cout << endl;
//			//cout << v2;
//		}
//		else if (check == 2)
//		{
//			cout << "Enter Array 1: " << endl;
//			cin >> v1;
//			cout << "Enter Array 2: " << endl;
//			cin >> v2;
//		    v1 + v2;
//			cout << endl;
//
//			//cout << v3;
//		}
//		else if (check == 3)
//		{
//			cin >> v1;
//			cout << "Capacity is : " << v1.getCapacity();
//		}
//		else if (check == 4)
//		{
//			cin >> v1;
//			--v1;
//			cout << v1;
//		}
//		else if (check == 5)
//		{
//			cin >> v1;
//			cout << v1;
//			v2 = v1;
//			cout << "\nDEEP COPY DONE!!" << endl;
//			cout << v2;
//		}
//		else if (check == 6)
//		{
//			cin >> v1;
//			cout << "enter index: ";
//			cin >> val;
//			if (v1[val] == true)
//			{
//				cout << "yes index avalaible" << endl;
//				cout << v1 << endl;
//			}
//			else
//				cout << " index not avaliable" << endl;
//		}
//		cout << "Enter 1 to exit and 0 to continue : ";
//		cin >> i;
//		while (i != 0 && i != 1)
//		{
//			cout << "Enter correct option  0 and 1 only Thanks !! ";
//			cin >> i;
//		}
//	}
//	cout << endl << "Program Completed Successfully" << endl;
//	system("pause");
//	return 0;
//}