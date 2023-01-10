//#include<iostream>
//using namespace std;
//
//void sort_fun(int *arr, int size)
//{
//	int temp;
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size - 1; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//void print(int *arr, int size)
//{
//	cout << "Array is : ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ",";
//	}
//	cout << endl;
//}
//
//int binarysearch(const int *arr, int num, int low, int high)
//{
//	if (low>high)
//		return -1;
//	else
//	{
//		int mid = (low + high) / 2;
//		if (num == arr[mid])
//		{
//			return mid;
//		}
//		else if (num > arr[mid])
//		{
//			binarysearch(arr, num, mid + 1, high);
//		}
//		else
//			binarysearch(arr, num, low, mid - 1);
//	}
//}
//
//
//int main()
//{
//	int *arr, size = 0, num = 0, index;
//	cout << "Enter size of array : ";
//	cin >> size;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Enter index " << i << " : ";
//		cin >> arr[i];
//	}
//	print(arr, size);
//	sort_fun(arr, size);
//	print(arr, size);
//	cout << "Enter number you want to search : ";
//	cin >> num;
//	index = binarysearch(arr, num, 0, size);
//	if (index == -1)
//	{
//		cout << "Element not found in array" << endl;
//	}
//	else
//		cout << "Element found at index : " << index << endl;
//	delete[] arr;
//	system("pause");
//	return 0;
//}