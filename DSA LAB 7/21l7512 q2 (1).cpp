////Write a Program in which you compute A/B and A%B and the only operations allowed are
////subtraction and addition.
////I.The algorithm must take O(B) times additions / subtractions.
//
//
//#include<iostream>
//using namespace std;
//
//int division(int a, int b)
//{
//	if (a < b)//base case if number is less than divisior
//	{
//		return 0;
//	}
//	return 1 + division(a - b, b);//subtracting b from a and adding 1 each time to answer
//}
//
//int mod(int a, int b)
//{
//	if (a < b)//if num1 gets smaller from num2
//	{
//		return a;
//	}
//	return mod(a - b, b);//else subtract the b from a
//}
//int main()
//{
//	int a, b;
//	cout << "Enter a : ";
//	cin >> a;
//	cout << "Enter b : ";
//	cin >> b;
//
//	cout << "A/B = " << division(a, b) << endl;
//	cout << "A%B = " << mod(a, b) << endl;
//	system("pause"); 
//	return 0;
//}