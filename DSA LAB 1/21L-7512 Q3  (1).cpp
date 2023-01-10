//#include<iostream>
//using namespace std;
//
//void Merge(int* arrm, int leftm, int midm, int rightm,int size)
//{
//	int ind1 = leftm;//three variables working as index pointers
//	int ind2 = midm + 1;
//	int ind3 = leftm;
//	int* newarr = new int[size];//new temp array for placing sorted array ele
//	for (int i = 0; i < size; i++)//initillizing array to 0
//	{
//		newarr[i] = 0;
//	}
//	while (ind1 <= midm && ind2 <= rightm)//condition of placing in temp array till end of sub arrays
//	{
//		if (arrm[ind1] <= arrm[ind2])//putting the one ele which is smallest in both sub arrays
//		{
//			newarr[ind3] = arrm[ind1];
//			ind1++;
//			ind3++;
//		}
//		else
//		{
//			newarr[ind3] = arrm[ind2];
//			ind2++;
//			ind3++;
//		}
//	}
//	while (ind1 <= midm) //if first array is smallest and already sorted
//	{
//		newarr[ind3] = arrm[ind1];
//		ind1++;
//		ind3++;
//	}
//	while (ind2 <= rightm) //if second array is greater and already sorted
//	{
//		newarr[ind3] = arrm[ind2];
//		ind2++;
//		ind3++;
//	}
//	for (int i = leftm; i <= rightm; i++)//loop for putting back into original array
//	{
//		arrm[i] = newarr[i];
//	}
//}
//void Merge_Sort(int* arr, int left, int right,int size)
//{
//	if (left < right)//continue till left and right becomes equal
//	{
//		int mid = (left + right) / 2;//taking mid of sub array
//		Merge_Sort(arr, 0, mid,size);//again sorting sub array // recusrive approach
//		Merge_Sort(arr, mid + 1, right,size);//second part of sub array
//		Merge(arr, left, mid, right,size); //function to add arrays //joining or merging
//	}
//}
//void display(int* arr, int size)
//{
//	cout << "Array is : ";//Printing function
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ",";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int* arr, size = 0;
//	cout << "Enter the size of array : ";//taking inputs from user
//	cin >> size;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Enter the value at index " << i << " : ";
//		cin >> arr[i];
//	}
//	cout << "Original Un-sorted array" << endl;
//	display(arr, size);//displaying un sorted array
//	Merge_Sort(arr, 0, size - 1,size);// function for sorting
//	cout << "Merge-sorted array" << endl;
//	display(arr, size);//displaying sorted array
//	system("pause");
//	return 0;
//}