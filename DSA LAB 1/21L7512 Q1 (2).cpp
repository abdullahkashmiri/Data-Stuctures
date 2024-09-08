//#include<iostream>
//using namespace std;
//
//
//void selectionsort(int *arr, int size)
//{
//	int min, temp;
//	for (int i = 0; i < size; i++)
//	{
//		min = i;
//		temp = arr[i];
//		for (int j = i; j < size; j++)
//		{
//			
//			if (temp>arr[j])
//			{
//				min = j;
//				temp = arr[j];
//			}
//		}
//		temp = arr[i];
//		arr[i] =arr[min] ;
//		arr[min] = temp; 
//	}
//	cout << "Array sorted Successfully" << endl;
//}
//
//void display(int *arr, int size)
//{
//	cout << "Array is : ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ",";
//	}
//	cout << endl;
//}
//
//void Binarysearch(int *arr, int size)
//{
//	
//	int find, low = 0, high = size - 1, mid = 0;
//	cout << "Enter number you want to search : ";
//	cin >> find;
//
//
//	for (int i = 0; i < size; i++)
//	{
//		mid = (low + high) / 2;
//		if (find == arr[mid])
//		{
//				cout << "found at index " << mid << endl;
//				arr[mid] = -9999;
//		}
//		else if (find>arr[mid])
//		{
//			low = mid++;
//		}
//		else
//			high=mid--;
//	}
//
//}
//
//
//	int main()
//{
//		int *arr = NULL, size = 0;
//		cout << "Enter the size of Array : " << endl;
//		cin >> size;
//		arr = new int[size];
//
//		for (int i = 0; i < size; i++)
//		{
//			cout << "Enter element no " << i << " : ";
//			cin >> arr[i];
//		}
//	display(arr, size);
//	selectionsort(arr, size);
//	display(arr, size);
//	Binarysearch(arr, size);
//
//
//
//
//	system("pause");
//	return 0;
//}