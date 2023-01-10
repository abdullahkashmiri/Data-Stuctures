//Write the recursive and iterative code for Fibonacci number computation.
//I.Analyze why Iteration is working so fast as compared to the recursive implementation of
//Fibonacci Numbers.
//
//#include<iostream>
//using namespace std;
//
//int fibonacci(int n1, int n2, int index,int count)
//{
//	if (index < 0)
//	{
//		cout << "Error Occured " << endl;
//		return -1;
//	}
//	if (count== index)
//	{
//		return n1;
//	}
//	int temp = n2;
//	n2 = n1 + n2;
//	n1 = temp;
//	return fibonacci(n1, n2, index, count + 1);
//}
//int main()
//{
//	int index = 0;
//	cout << "Enter the index of fibonacci series : ";
//	cin >> index;
//	cout << fibonacci(0, 1, index, 0) << endl;
//
//	system("pause");
//	return 0;
//}