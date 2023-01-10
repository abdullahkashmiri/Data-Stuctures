//#include<iostream>
//using namespace std;
//
//
//class Node
//{
//public:
//	Node*left;
//	Node*right;
//	int marks;
//	char grade;
//	Node()
//	{
//		left = NULL;
//		right = NULL;
//		marks = 0;
//		grade = '\0';
//	}
//	Node(int mar)
//	{
//		left = NULL;
//		right = NULL;
//		marks = mar;
//	}
//};
//
//class BST
//{
//private:
//	Node*root;
//public:
//	BST()
//	{
//		root = NULL;
//	}
//	void insert(int marks)
//	{
//		insertR(root, marks);
//	}
//	void insertR(Node *&node, int mark)
//	{
//		if (node == NULL)
//		{
//			node = new Node(mark);
//			cout << "MARKS insert : " << mark << endl;
//			return;
//		}
//		else if (node->marks > mark)
//		{
//			insertR(node->left, mark);
//		}
//		else if (node->marks < mark)
//		{
//			insertR(node->right, mark);
//		}
//	}
//	void Assign_Grades()
//	{
//		cout << "Assigning Grades" << endl;
//		 AssignGradeR(root);
//	}
//	void AssignGradeR(Node *&node)
//	{
//		if (node)
//		{
//			AssignGradeR(node->left);
//			node->grade = Calculategrade(node->marks);
//			AssignGradeR(node->right);
//		}
//	}
//	char Calculategrade(int mark)
//	{
//		if (mark > 80)
//		{
//			return 'A';
//		}
//		else if (mark <= 80 && mark >= 70)
//		{
//			return 'B';
//		}
//		else if (mark <= 69 && mark >= 50)
//		{
//			return 'C';
//		}
//		else
//			return 'F';
//	}
//	void inorder()
//	{
//		cout << "INORDER PRINTING" << endl;
//		inorderR(root);
//		cout << endl;
//	}
//
//	void inorderR(Node *&node)
//	{
//		if (node)
//		{
//			inorderR(node->left);
//			cout  << node->marks <<"->" << node->grade <<" , ";
//			inorderR(node->right);
//		}
//	}
//	void StudentsInEachGrade()
//	{
//		cout << "Students Grades " << endl;
//		int a = 0, b = 0, c = 0, f = 0;
//		StudentsInEachGradeR(root, a, b, c, f);
//		cout << "A Grade = " << a << " Students" << endl;
//		cout << "B Grade = " << b << " Students" << endl;
//		cout << "C Grade = " << c << " Students" << endl;
//		cout << "F Grade = " << f << " Students" << endl;
//	}
//	void StudentsInEachGradeR(Node *&node, int &a, int & b, int & c, int & f)
//	{
//		if (node)
//		{
//			StudentsInEachGradeR(node->left, a, b, c, f);
//			if (node->grade == 'A')
//				a++;
//			else if (node->grade == 'B')
//				b++;
//			else if (node->grade == 'C')
//				c++;
//			else
//				f++;
//			StudentsInEachGradeR(node->right, a, b, c, f);
//		}
//	}
//	
//};
//
//int main()
//{
//	BST bst;
//	bst.insert(70);
//	bst.insert(90);
//	bst.insert(80);
//	bst.insert(56);
//	bst.insert(39);
//	bst.insert(99);
//	bst.insert(19);
//
//	cout << "Before grading" << endl;
//	bst.inorder();
//	bst.Assign_Grades();
//	cout << "After grading" << endl;
//	bst.inorder();
//
//	bst.StudentsInEachGrade();
//	cout << endl << endl<< "Program Terminated SccessFully" << endl;
//	system("pause");
//	return 0;
//}