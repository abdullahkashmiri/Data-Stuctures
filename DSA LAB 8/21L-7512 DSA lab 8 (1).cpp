//#include<iostream>
//using namespace std;
//
//template <class T>
//class Node
//{
//public:
//	T data;
//	Node*left;
//	Node*right;
//	Node()
//	{
//		data = NULL;
//		right = left = NULL;
//	}
//	Node(T d)
//	{
//		data = d;
//		left = NULL;
//		right = NULL;
//	}
//};
//
//template<class T>
//class BST
//{
//private:
//	Node<T>*root;
//public:
//	BST()
//	{
//		root = NULL;
//	}
//	bool insertR(T data, Node<T> *&node)
//	{
//		if (node == NULL)
//		{
//			node = new Node<T>(data);
//			return true;
//		}
//		else if (node->data > data)
//		{
//			insertR(data, node->left);
//		}
//		else if (node->data < data)
//		{
//			insertR(data, node->right);
//		}
//		else if (node->data == data)
//		{
//			return false;
//		}
//	}
//	void insert(T data)
//	{
//		if ((insertR(data, root)) == true)
//		{
//			cout << "DATA : " << data;
//			cout << " Inserted SuccessFully !!" << endl;
//		}
//		else
//		{
//			cout << "DATA : " << data;
//			cout << " Duplicate!!\n Already Exist!! " << endl;
//		}
//	}
//
//	void Visit(Node<T> *node)
//	{
//		cout << node->data << endl;
//	}
//	void InOrder(Node<T> *&node)
//	{
//		if (node != NULL)
//		{
//			InOrder(node->left);
//			Visit(node);
//			InOrder(node->right);
//		}
//	}
//	void InOrderPrint()
//	{
//		InOrder(root);
//	}
//	void PreOrder(Node<T> *&node)
//	{
//		if (node != NULL)
//		{
//			Visit(node);
//			PreOrder(node->left);
//			PreOrder(node->right);
//		}
//	}
//	void PreOrderPrint()
//	{
//		PreOrder(root);
//	}
//	void PostOrder(Node<T> *&node)
//	{
//		if (node != NULL)
//		{
//			PostOrder(node->left);
//			PostOrder(node->right);
//			Visit(node);
//		}
//	}
//	void PostOrderPrint()
//	{
//		PostOrder(root);
//	}
//	bool searchR(T data, Node<T> *&node)
//	{
//		if (node == NULL)
//		{
//			return false;
//		}
//		if (node->data == data)
//		{
//			//	cout << "DATA FOUND : " << data << endl;
//			return true;
//		}
//		else if (node->data > data)
//		{
//			searchR(data, node->left);
//		}
//		else if (node->data < data)
//		{
//			searchR(data, node->right);
//		}
//	}
//	void search(T data)
//	{
//
//		if ((searchR(data, root)) == true)
//		{
//			cout << "DATA Found : " << data;
//			cout << " Searched SuccessFully !!" << endl;
//		}
//		else
//		{
//			cout << "DATA : " << data << " not Found" << endl;
//		}
//	}
//	int lengthR(Node<T> *&node, int &count)
//	{
//		if (node != NULL)
//		{
//			count++;
//			lengthR(node->left, count);
//			lengthR(node->right, count);
//		}
//		return count;
//	}
//	int length()
//	{
//		int count = 0;
//		lengthR(root, count);
//		return count;
//	}
//
//	int leafcountR(Node<T> *&node, int &count)
//	{
//		if (node != NULL)
//		{
//			if (!node->left  && !node->right)
//			{
//				count++;
//			}
//			leafcountR(node->left, count);
//			leafcountR(node->right, count);
//		}
//		return count;
//	}
//	int leafcount()
//	{
//		int count = 0;
//		leafcountR(root, count);
//		return count;
//	}
//	~BST()
//	{
//		Destroy(root);
//	}
//	void Destroy(Node<T>*&node)
//	{
//		/*	if (node==NULL)
//		{
//		return;
//		}*/
//		if (node != NULL)
//		{
//
//			//if (node->left!=NULL)
//			Destroy(node->left);
//			//if (node->right!=NULL)
//			Destroy(node->right);
//			delete node;
//			return;
//		}
//	}
//
//	void copyConstructor(BST<T> *&tree)
//	{
//		if (tree.node != NULL)
//		{
//			copyConstructor(tree.node->left);
//			copyConstructor(tree.node->right);
//			insert(tree.node->data);
//		}
//	}
//	BST(BST<T>*&tree)
//	{
//		copyConstructor(tree);
//	}
//};
//
//int main()
//{
//	BST<int> tree;
//	tree.InOrderPrint();
//
//	tree.insert(500);
//	tree.insert(1000);
//	tree.insert(1);
//	tree.insert(600);
//	tree.insert(700);
//	tree.insert(10);
//	tree.insert(30);
//	tree.insert(9000);
//	tree.insert(50000);
//	tree.insert(20);
//
//	cout << " Printing data using recursive inorder traversal : " << endl;
//	tree.InOrderPrint();
//	cout << "Copy Constructor" << endl;
//	BST<int>tree1(tree);
//	cout << " Printing data using recursive Pre traversal : " << endl;
//
//	tree.PreOrderPrint();
//	cout << " Printing data using recursive Post traversal : " << endl;
//
//	tree.PostOrderPrint();
//	cout << "Search" << endl;
//	tree.search(1);
//	tree.search(30);
//	tree.search(50);
//
//	cout << "Length OF Tree is : " << tree.length() << endl;
//	cout << "Leaf Count OF Tree is : " << tree.leafcount() << endl;
//
//	cout << endl;
//
//
//
//	system("pause");
//	return 0;
//}