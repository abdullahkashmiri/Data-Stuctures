////4. Write the recursive and iterative code for computing the Tri - Sum sequence : 1, 2, 3, 6, 11, 20, 37…
////I.Write the recursive mathematical formulation.
////II.Write the recursive code for the Sequence generator
////III.Analyze what will be its time complexity(the approximate number of times the recursive call
////will be called.
//
//#include<iostream>
//using namespace std;
//
//int trisum(int n1, int n2,int n3, int index,int count)
//{
//	if (index < 0)
//	{
//		cout << "Error Occured " << endl;
//		return -1;
//	}
//	if (count == index)
//	{
//		return n1;
//	}
//	cout << n1 << ",";
//
//	int temp1 = n2;// second num
//	int temp2 = n3;//third num
//	n2 = n1 + n2;//adding n2
//	n3 = n2 + n3;//adding n3
//	n1 = temp1;//restoring val
//	n2 = temp2;//restoring val
//	return trisum(n1, n2, n3,index, count + 1);
//}
//int main()
//{
//	int index = 0;
//	cout << "Enter the index of tri sum series : ";
//	cin >> index;
//	cout << trisum(1,2,3, index, 0) <<" ."<< endl;
//	system("pause");
//	return 0;
//}