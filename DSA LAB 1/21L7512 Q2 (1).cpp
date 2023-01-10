//#include<iostream>
//using namespace std;
//
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
//void BubbleSort(int *arr, int size)
//{
//	int temp;
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (arr[i]<arr[j])
//			{
//				temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//	cout << "Sorting Done successfully" << endl;
//}
//int main()
//{
//	int *arr,  size =0;
//
//	cout << "Enter the size of Array : ";
//	cin >> size;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Enter element on index " << i << " : ";
//		cin >> arr[i];
//	}
//	display(arr, size);
//	BubbleSort(arr, size);
//	display(arr, size);
//
//	system("pause");
//	return 0;
//}