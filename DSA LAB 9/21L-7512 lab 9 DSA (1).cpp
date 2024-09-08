//#include<iostream>
//using namespace std;
//
//template<class T>
//class Node
//{
//public:
//	T value;
//	Node<T>*left;
//	Node<T>*right;
//	int height;
//	Node()
//	{
//		value = NULL;
//		left = NULL;
//		right = NULL;
//		height = 0;
//	}
//	Node(T val)
//	{
//		value = val;
//		left = NULL;
//		right = NULL;
//		height = 1;
//	}
//};
//template<class T>
//class AVLTree
//{
//	Node<T>* root;
//	int balanceFactor;
//public:
//	AVLTree()
//	{
//		root = NULL;
//		balanceFactor = 0;
//	}
//	int cheight(Node<T>*node)
//	{
//		if (!node)
//		{
//			return 0;
//		}
//		return node->height;
//	}
//	int Max(T a, T b)
//	{
//		if (a > b)
//			return a;
//		else
//			return b;
//	}
//	Node<T>*RotateLeft(Node<T>*x)
//	{
//		Node<T>*y = x->right;
//		Node<T>*temp = y->left;
//		y->left = x;
//		x->right = temp;
//		x->height = Max(cheight(x->left), cheight(x->right)) + 1;
//		y->height = Max(cheight(y->left), cheight(y->right)) + 1;
//		return y;
//	}
//
//	Node<T>*RotateRight(Node<T>*y)
//	{
//		Node<T>*x = y->left;
//		Node<T>*temp = x->right;
//		x->right = y;
//		y->left = temp;
//		y->height = Max(cheight(y->left), cheight(y->right)) + 1;
//		x->height = Max(cheight(x->left), cheight(x->right)) + 1;
//		return x;
//	}
//
//	int getbalancefactor(Node<T>*node)
//	{
//		if (!node)
//		{
//			return 0;
//		}
//		else
//			return(cheight(node->left) - cheight(node->right));
//	}
//
//	void insert(T val)
//	{
//		root = insertR(root, val);
//	}
//	Node<T>* insertR(Node<T>* node, T val)
//	{
//		if (node == NULL)
//		{
//			node = new Node<T>(val);
//			return node;
//		}
//		if (node->value > val)
//		{
//			node->left = insertR(node->left, val);
//		}
//		else if (node->value < val)
//		{
//			node->right = insertR(node->right, val);
//		}
//		else if (node->value == val)
//		{
//			return node;
//		}
//
//		node->height = Max(cheight(node->left), cheight(node->right)) + 1;
//		balanceFactor = getbalancefactor(node);
//		if (balanceFactor>1)
//		{
//			if (node->left->value > val)//R Rotation
//			{
//				return RotateRight(node);
//			}
//			else if (node->left->value < val)//LR Rotation
//			{
//				node->left = RotateLeft(node->left);
//				return RotateRight(node);
//			}
//		}
//		else if (balanceFactor < -1)
//		{
//			if (node->right->value < val)//L Rotation
//			{
//				return RotateLeft(node);
//			}
//			else if (node->right->value > val)//RL Rotation
//			{
//				node->right = RotateRight(node->right);
//				return RotateLeft(node);
//			}
//		}
//		return node;
//	}
//
//	bool isAVL()
//	{
//		cout << "---AVL TREE CHECKING---" << endl;
//		bool flag = true;
//		isAVLR(root, flag);
//		return flag;
//	}
//	void isAVLR(Node<T>*node, bool &flag)
//	{
//		if (node)
//		{
//			isAVLR(node->left, flag);
//			isAVLR(node->right, flag);
//			balanceFactor = getbalancefactor(node);
//			if (balanceFactor > 1 || balanceFactor < -1)
//			{
//				flag = false;
//			}
//		}
//	}
//	bool search(T val)
//	{
//		bool flag = false;
//		searchR(root, val, flag);
//		return flag;
//	}
//	void searchR(Node<T>*node, T val, bool &flag)
//	{
//		if (node)
//		{
//			if (node->value == val)
//			{
//				flag = true;
//				return;
//			}
//			else if (node->value > val)
//			{
//				searchR(node->left, val, flag);
//			}
//			else if (node->value < val)
//			{
//				searchR(node->right, val, flag);
//			}
//		}
//	}
//	T find_min()
//	{
//		cout << "Find minimum" << endl;
//		if (root!=NULL)
//		{
//			T min = root->value;
//			find_minR(root,min);
//			return min;
//		}
//		return -90909;
//	}
//	void find_minR(Node<T>*node,T &min)
//	{
//		if (node)
//		{
//			if (node->value < min)
//			{
//				min = node->value;
//			}
//			find_minR(node->left, min);
//			find_minR(node->right, min);
//		}
//	}
//	T find_2min()
//	{
//		cout << "Find 2nd minimum" << endl;
//		if (root != NULL)
//		{
//			T min2 = root->value;
//			T min = root->value;
//			find_minR(root, min);
//			find_2minR(root, min, min2);
//			return min2;
//		}
//		return -90909;
//	}
//	void find_2minR(Node<T>*node, T &min,T &min2)
//	{
//		if (node)
//		{
//			if (node->value > min &&node->value<min2)
//			{
//				min2 = node->value;
//			}
//			find_2minR(node->left, min,min2);
//			find_2minR(node->right, min,min2);
//		}
//	}
//	void PostOrder()
//	{
//		cout << "Post Order Printing " << endl;
//		postOrderR(root);
//		cout << endl;
//	}
//	void postOrderR(Node<T>* node)
//	{
//		if (node)
//		{
//			postOrderR(node->left);
//			postOrderR(node->right);
//			cout << node->value << "->";
//		}
//	}
//	void PreOrder()
//	{
//		cout << "Pre Order Printing " << endl;
//		preOrderR(root);
//		cout << endl;
//	}
//	void preOrderR(Node<T>* node)
//	{
//		if (node)
//		{
//			cout << node->value << "->";
//			preOrderR(node->left);
//			preOrderR(node->right);
//		}
//	}
//	void InOrder()
//	{
//		cout << "IN Order Printing " << endl;
//		inOrderR(root);
//		cout << endl;
//	}
//	void inOrderR(Node<T>* node)
//	{
//		if (node)
//		{
//			inOrderR(node->left);
//			cout << node->value << "->";
//			inOrderR(node->right);
//		}
//	}
//};
//
//
//
//
//int main()
//{
//	AVLTree <int> avl;
//	avl.insert(1);
//	avl.insert(5);
//	avl.insert(4);
//	avl.insert(2);
//	avl.insert(0);
//	avl.insert(3);
//	avl.PreOrder();
//	avl.InOrder();
//	avl.PostOrder();
//	if (avl.isAVL())
//	{
//		cout << "AVL TREE (Balanced)" << endl;
//	}
//	else
//		cout << "Not AVL " << endl;
//	int val;
//	cout << "Enter Value you want to Search : ";
//	cin >> val;
//	if (avl.search(val))
//	{
//		cout << val << " found successfully" << endl;
//	}
//	else
//		cout << val << " not found" << endl;
//	val = avl.find_min();
//	if (val == -90909)
//	{
//		cout << "Empty AVL" << endl;
//	}
//	else
//		cout << "Minimum Vlaue is : " << val << endl;
//	val = avl.find_2min();
//	if (val == -90909)
//	{
//		cout << "Empty AVL" << endl;
//	}
//	else
//		cout << "Minimum Vlaue is : " << val << endl;
//
//	cout << endl;
//	system("pause");
//	return 0;
//}