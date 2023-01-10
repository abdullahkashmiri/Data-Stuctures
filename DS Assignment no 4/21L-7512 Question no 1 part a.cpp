//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//template<class K, class V>
//class Node// Node class template based
//{
//public:// Data members
//	K key;
//	V value;
//	Node* left;
//	Node* right;
//	int height;
//	Node()//Default constructor
//	{
//		key = NULL;
//		value = NULL;
//		left = NULL;
//		right = NULL;
//		height = 0;
//	}
//	Node(K k, V v)// Overloaded constructor
//	{
//		key = k;
//		value = v;
//		left = NULL;
//		right = NULL;
//		height = 0;
//	}
//};
//
//template<class K, class V>
//class SpecialBST// Special BST class Template based
//{
//private://private data members
//	Node<K, V>* Root;
//	bool flag_insertion;
//	bool flag_key;
//	bool leafnodeflag;
//	vector<pair<K, V>>traverse;
//public:// member functions
//	SpecialBST()//Constructor
//	{
//		Root = NULL;
//		flag_insertion = false;
//		flag_key = false;
//		leafnodeflag = false;
//	}
//	~SpecialBST()//Destructor
//	{
//		cout << "Destructor here" << endl;
//		Destroy(Root);
//	}
//	void Destroy(Node<K, V>*& node)//Destroy member function for destructor
//	{
//		if (node)
//		{
//			Destroy(node->left);
//			Destroy(node->right);
//			delete node;
//		}
//	}
//	//----------------------------------------------------------------------------------------------------
//	// INSERT FUNCTION
//	//----------------------------------------------------------------------------------------------------
//	bool insert(K key, V value)// Insert wrapped function
//	{
//		flag_insertion = false;// initillizing to false insertion flag 
//		Root = insertR(Root, key, value);// Recursive Insertion
//		if (flag_insertion)
//		{
//			cout << "Inserted SuccessFully Key : " << key << " Value : " << value << endl;
//		}
//		else
//			cout << "Duplicate Exist Key : " << key << " Value : " << value << endl;
//		return flag_insertion;// returning flag value
//	}
//	Node<K, V>* insertR(Node <K, V>* node, K key, V value)// recursive insertion function
//	{
//		if (node == NULL)//leaf node reached
//		{
//			Node<K, V>* newnode = new Node<K, V>(key, value);// make newnode 
//			flag_insertion = true;// inserted successfully
//			return newnode;
//		}
//		else if (node->key > key)// left child condition
//		{
//			Node<K, V>* newnode = insertR(node->left, key, value);// inserting new node at left
//			node->left = newnode->right;// left child of parent node pointing to new node right child
//			newnode->right = node;//newnode right child pointing to parent node
//			return newnode;// return back newnode
//		}
//		else if (node->key < key)// right child condition
//		{
//			Node<K, V>* newnode = insertR(node->right, key, value);// inserting new node aty the right 
//			node->right = newnode->left;// right child of parent node pointing to new node left child
//			newnode->left = node;//new node left child pointing to parent node
//			return newnode;// return back newnode
//		}
//		else if (node->key == key)// duplicate key
//		{
//			flag_insertion = false;// flag false duplication
//			return node;// return back parent node
//		}
//	}
//	//----------------------------------------------------------------------------------------------------
//	// SEARCH FUNCTION
//	//----------------------------------------------------------------------------------------------------
//	V* Search(K key)// search function wrapper function
//	{
//		flag_key = false;// making found flag false
//		Root = searchR(Root, key);// recursive function for searching
//		if (flag_key == true)	// true if found so return value
//		{
//			return (&Root->value);// return value of root because searched element is at root now
//		}
//		else
//		{
//			return nullptr;// else return nullptr
//		}
//	}
//	Node<K, V>* searchR(Node<K, V>* node, K key)// recursive function for search
//	{
//		if (node == NULL)// leaf node reached
//		{
//			flag_key = false;// flag to false not found
//			return NULL;// return  NULL ptr
//		}
//		else if (key == node->key)// Key found
//		{
//			flag_key = true;// update flag
//			return node;
//		}
//		else if (node->key > key)//left child case
//		{
//			Node<K, V>* newnode = searchR(node->left, key); //Right Rotation
//			if (newnode == NULL)//not found
//			{
//				return node;// return parent node
//			}
//			node->left = newnode->right;//pointing node left child to newnode right child
//			newnode->right = node;// pointing newnode right child to parent node
//			return newnode;//returning newnode
//		}
//		else if (node->key < key)//right child case
//		{
//			Node<K, V>* newnode = searchR(node->right, key);//left rotation
//			if (newnode == NULL)//not found
//			{
//				return node;
//			}
//			node->right = newnode->left;// pointing parent node right to newnode left
//			newnode->left = node;// pointing newnode left to parent
//			return newnode;//returning newnode
//		}
//	}
//	//----------------------------------------------------------------------------------------------------
//	// DELETION FUNCTION
//	//----------------------------------------------------------------------------------------------------
//	bool delete_(K key)// wrapper function for delete
//	{
//		leafnodeflag = false;// flag for checking deletion
//		flag_key = false;// making found flag false
//		Root = deleteR(Root, key, leafnodeflag);// recursive function for searching
//		return flag_key;
//	}
//	Node<K, V>* deleteR(Node<K, V>* node, K key, bool& leafnodeflag)//recursive delete function
//	{
//		if (node == NULL && leafnodeflag)// leaf node reached
//		{
//			flag_key = true;// flag to false not found
//			return node;// return  NULL ptr
//		}
//		else if (node == NULL)// leaf node reached
//		{
//			flag_key = false;// flag to false not found
//			return NULL;// return  NULL ptr
//		}
//		else if (key == node->key)// Key found //deletion here
//		{
//			flag_key = true;// update flag
//			Node<K, V>* temp = delete_Node(node, leafnodeflag);
//			if (temp != NULL)
//			{
//				node = temp;
//			}
//			return node;
//		}
//		else if (node->key > key)//left child case
//		{
//			Node<K, V>* newnode = deleteR(node->left, key, leafnodeflag);//Right Rotation
//			if (newnode == NULL)//not found
//			{
//				return node;// return parent node
//			}
//			node->left = newnode->right;//pointing node left child to newnode right child
//			newnode->right = node;// pointing newnode right child to parent node
//			return newnode;//returning newnode
//		}
//		else if (node->key < key)//right child case
//		{
//			Node<K, V>* newnode = deleteR(node->right, key, leafnodeflag);//left rotation
//			if (newnode == NULL)//not found
//			{
//				return node;
//			}
//			node->right = newnode->left;// pointing parent node right to newnode left
//			newnode->left = node;// pointing newnode left to parent
//			return newnode;//returning newnode
//		}
//	}
//	Node<K, V>* delete_Node(Node<K, V>*& node, bool& leafnodeflag)// delet node function
//	{
//		Node<K, V>* temp = node;
//		if (node->left == NULL)// right child exit
//		{
//			if (node->right == NULL)// no child
//			{
//				node = NULL;
//				leafnodeflag = true;
//			}
//			else
//				node = node->right;
//			delete temp;
//			return node;
//		}
//		else if (node->right == NULL)// left child exits
//		{
//			if (node->left == NULL)
//				node = NULL;
//			else
//				node = node->left;
//			delete temp;
//			return node;
//		}
//		else// both child case
//		{
//			Node<K, V>* temp1 = node;
//			K key;
//			getPredecessor(node->left, key);// left largest node
//			node->key = key;
//			deleteR(node->left, key, leafnodeflag);// delete that node
//			return temp1;
//		}
//	}
//	void getPredecessor(Node<K, V>* node, K& key)// last node of one side
//	{
//		while (node->right != NULL)
//		{
//			node = node->right;
//		}
//		key = node->key;
//	}
//	//-----------------------------------------------------------------------------
//	// Get Values fnunction level wise
//	//-----------------------------------------------------------------------------
//	vector<pair<K, V>>* getValuesLevelWise()//function get values wise
//	{
//		traverse.clear();//clearing vector
//		levelOrderR(Root);// getting values level wise
//		return &traverse;// returning vector
//	}
//	void levelOrderR(Node<K, V>* node)
//	{
//		if (node == NULL)//empty tree
//		{
//			return;
//		}
//		queue<Node<K, V>*>Q;// dynamic queue
//		Q.push(node);
//		while (!Q.empty())
//		{
//			Node<K, V>* front = Q.front();
//			Q.pop();
//			traverse.push_back(make_pair(front->key, front->value));//pushing values
//			if (front->left != NULL)
//			{
//				Q.push(front->left);
//			}
//			if (front->right != NULL)
//			{
//				Q.push(front->right);
//			}
//		}
//	}
//	//-----------------------------------------------------------------------------
//	// Get Values function order wise
//	//-----------------------------------------------------------------------------
//	vector<pair<K, V>>* getValuesInOrder()// values in order function
//	{
//		traverse.clear();// clearing vector
//		inorderR(Root);// getting values in order recursively
//		return&traverse;// returining vector
//	}
//	void inorderR(Node<K, V>* node)// inorder traversal of tree
//	{
//		if (node)
//		{
//			inorderR(node->left);
//			traverse.push_back(make_pair(node->key, node->value));//getting values in vector
//			inorderR(node->right);
//		}
//	}
//	//-----------------------------------------------------------------------------
//	// Printing Function
//	//-----------------------------------------------------------------------------
//	void PostOrder()//post order printing
//	{
//		cout << "Post Order Printing" << endl;
//		PostOrderR(Root);
//		cout << endl;
//	}
//	void PostOrderR(Node<K, V>*& node)// post order recursive
//	{
//		if (node)
//		{
//			PostOrderR(node->left);
//			PostOrderR(node->right);
//			cout << "Node Key : " << node->key << " Node Value : " << node->value << endl;
//		}
//	}
//	void PreOrder()// preorder printig
//	{
//		cout << "Pre Order Printing" << endl;
//		PreOrderR(Root);
//		cout << endl;
//	}
//	void PreOrderR(Node<K, V>*& node)// preorder printing recursively
//	{
//		if (node)
//		{
//			cout << "Node Key : " << node->key << " Node Value : " << node->value << endl;
//			PreOrderR(node->left);
//			PreOrderR(node->right);
//		}
//	}
//};
//int main()
//{
//	SpecialBST<int,char> sbst;
//	sbst.insert(5, 'e');
//	sbst.insert(4, 'd');
//	sbst.insert(1, 'a');
//	sbst.insert(3, 'c');
//	sbst.insert(2, 'b');
//
//	sbst.PostOrder();
//	sbst.PreOrder();
//	
//	int key;
//	char *value;
//	key = 3;
//	value = sbst.Search(key);
//	if (value)
//	{
//		cout << "Search Found! Key : " << key << " Value : " << value << endl;
//	}
//	else
//		cout << "Key : " << key << " Not found" << endl;
//	key = 7;
//	value=sbst.Search(key);
//	if (value)
//	{
//		cout << "Search Found! Key : " << key << " Value : " << value << endl;
//	}
//	else
//		cout << "Key : " << key << " Not found" << endl;
//
//	sbst.PostOrder();
//	sbst.PreOrder();
//
//	key = 2;
//	if (sbst.delete_(key))
//	{
//		cout << "Key : " << key << " deleted SuccessFully" << endl;
//	}
//	else 
//		cout << "Key : " << key << " Not found" << endl;
//	key = 10;
//	if (sbst.delete_(key))
//	{
//		cout << "Key : " << key << " deleted SuccessFully" << endl;
//	}
//	else
//		cout << "Key : " << key << " Not found" << endl;
//
//	sbst.PostOrder();
//	sbst.PreOrder();
//
//	return 0;
//}