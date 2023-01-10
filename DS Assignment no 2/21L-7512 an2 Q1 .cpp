//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<string>
//
//using namespace std;
//
//template<class T> //template Node class
//class Node {
//public://data members
//	T data;
//	Node<T>* next;
//	Node()//default constructor   O(1)
//	{
//		data = NULL;
//		next = NULL;
//	}
//	Node(T val)//overloaded constructor   O(1)
//	{
//		data = val;
//		next = NULL;
//	}
//};
//
//template<class T>//template class stack
//class Stack {
//	Node<T> head;
//public:
//	Stack()//default constructor   O(1)
//	{
//		head = NULL;
//	}
//	~Stack()//destructor   O(n)
//	{
//		Node<T>* previous = &head;
//		Node<T>* current = previous->next;
//		while (current != NULL)
//		{
//			previous = current;
//			current = current->next;
//			delete previous;
//		}
//	}
//	bool IsEmpty()//is empty function   O(1)
//	{
//		if (!head.next)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool push(const T& val)//push function   O(1)
//	{
//		Node<T>* newnode = new Node<T>(val);
//		newnode->next = head.next;
//		head.next = newnode;
//		return true;
//	}
//	bool pop(T& val)//pop function   O(1)
//	{
//
//		if (!IsEmpty())
//		{
//			Node<T>* previous = head.next;
//
//			Node<T>* current = previous->next;
//			val = previous->data;
//			head.next = current;
//			delete previous;
//			return true;
//
//		}
//		return false;
//
//	}
//	T top()//getting value of top function   O(1)
//	{
//		T val;
//		if (!head.next)
//			return NULL;
//		Node<T>* current = head.next;
//		val = current->data;
//		return val;
//	}
//};
//template <class T>//template class xml
//class XML : public Stack <T>
//{
//private://data members
//	Stack <T> s;
//	Stack<T>save;
//	Stack<T>check;
//	ifstream xml;
//	int lines;
//	string line;
//	T element;
//	T val;
//public:
//	XML()//default constructor   O(1)
//	{
//		line = "";
//		lines = 0;
//		val = NULL;
//		element = NULL;
//		xml.open("xmll.txt");
//		if (xml.fail())//checking file found or not
//		{
//			cout << "ERROR!!\tUnable to Open Input File" << endl;
//		}
//		else
//			cout << "XML Constructor Executed" << endl;
//	}
//	
//	void fun()// main logic function   O(n^2)
//	{
//
//		while (getline(xml, line)&&!xml.eof())//getting lines till file is empty
//		{
//			if (!s.IsEmpty())// if stack is not empty error found 
//			{
//				cout << "Error Occured at : ";
//				while (!s.IsEmpty())//printing errors found
//				{
//					s.pop(val);
//					cout << "No closing of : " << val << " found \t";
//				}
//				system("pause");
//			}
//			lines++;
//			cout << "\nCurrently Checking line no : " << lines << endl;//printing line no
//	        stringstream linestream(line);//taking line into stream
//			linestream >> element;
//			if (element == '<')
//			{
//				s.push(element);
//				linestream >> element;
//				if (element == '?')//for header and Attributes
//				{
//					prolog(line);//prolong function if prolong found
//					if (!s.IsEmpty())
//					{
//						cout << "\nError found at line " << lines << endl;
//					}
//				}
//				else if (element == '!')//for comment function 
//				{
//					comment(line);
//				}
//				else//For Tags and Attributes 
//				{
//					stringstream linestream(line);
//					T ele = NULL;
//					string str;
//					char a = 47;
//					bool f1 = false;//attribute checking till closing not found of attribute
//					bool flag = false, flag2 = false;//flag for opening tag completion  //flag 2 for closing tag of completion
//					while (linestream >> element)
//					{
//						if (element == '=' || f1 == true)//using f1 for attribute checking
//						{
//							if (f1 == true)
//							{
//								Tags(ele, flag, f1);//tags function
//							}
//							else
//								savetag();
//							linestream >> element;
//							Tags(element, flag, f1);//tags function
//							linestream >> element;
//							if (element == '>')
//							{
//								s.pop(val);
//							}
//							flag = true;
//						}
//						else if (element == '>'&& flag==false)
//						{
//							s.pop(val);
//							savetag();
//							flag = true;
//						}
//						else if (element == '<' && flag == true)//flag is being used to check the closing of an element tag
//						{
//							s.push(element);
//							linestream >> element;
//							if (element == a)
//							{
//								s.push(element);
//								s.pop(val);
//								flag2 = true;//closing tag found check flag
//								linestream >> str;
//								deletetag(str);
//							}
//							flag = false;//as closing found so set to default
//						}
//						else if (flag2 == true && element == '>')
//						{
//							s.pop(val);
//							flag2 = false;
//						}
//						else if (element == a)//flag is being used to check the closing of an element tag
//						{
//							linestream >> str;
//							deletetag(str);
//						}
//					}
//					if (s.IsEmpty())// if not empty then error found
//					{
//						cout << "\nNo Error found at line " << lines << endl;
//					}
//					else
//						cout << "\nError found at line " << lines << endl;
//				}
//			}
//			else
//				cout << "\nError found at line : " << lines <<" [<] not placed "<< endl;
//		}
//		if (!save.IsEmpty())
//		{
//			cout << "Closing tags of following are not found : ";
//			while (!check.IsEmpty())
//			{
//				check.pop(val);
//			}
//			while (!save.IsEmpty())
//			{
//				save.pop(val);
//				check.push(val);
//			}
//			while (!check.IsEmpty())
//			{
//				check.pop(val);
//				if (val == '=')
//					cout << "  ";
//				else
//					cout << val;
//			}
//		}
//		else 
//		{
//		//	cout << "						|--------------------|" << endl;
//		//	cout << "						| NO TAG ERROR FOUND | " << endl;
//		//	cout << "						|--------------------|" << endl;
//
//		}
//	}
//	void savetag()
//	{
//		cout << "SAVE TAG  " ;
//		string ele;
//		char e;
//		stringstream ls(line);
//		ls >> element;//excluding <
//		ls >> ele;//taking first word
//		stringstream lss(ele);
//		e = '=';
//		save.push(e);
//		while (lss>>e)
//		{
//			save.push(e);
//		}
//		if (save.top() == '>')
//		{
//			save.pop(val);
//		}
//	}
//	void deletetag(string str)
//	{
//		cout << "Delete Tag  ";
//		char e;
//		stringstream lss(str);
//		e = '=';
//		check.push(e);
//		while (lss >> e)
//		{
//			check.push(e);
//		}
//		if (check.top() == '>')
//		{
//			check.pop(val);
//			s.pop(val);
//		}
//		if(save.top()=='=')
//		save.pop(val);
//		while (save.top() == check.top() && !check.IsEmpty())
//		{
//			save.pop(val);
//			check.pop(val);
//		}
//		cout << endl;
//		if (check.IsEmpty())
//		{
//			cout << "closing tag found successfully" << endl;
//		}
//		else
//		{
//			cout << "Tag Error : " << str << endl;
//			system("pause");
//		}
//	}
//	void Tags(T ele, bool& f, bool& flag)//tags function   O(1)
//	{ 
//		Attribute(flag);
//		if (ele == '>')
//		{
//			s.pop(val);
//			f = true;
//			cout << " opening Tag of content element  ";
//		}
//	}
//	void prolog(string line)//prolong function   O(n)
//	{
//		bool flag = false;
//		stringstream linestream(line);
//		cout << "Prolog found here\t";
//		if (lines != 1)//if line is not 1 then error
//		{
//			return;
//		}
//		linestream >> element;
//		linestream >> element;
//		s.push(element);
//		while (linestream >> element)//while line not empty 
//		{
//			if (element == '"' || element == '\'' || flag == true)//Error giving on single qoutation '
//			{
//				Attribute(flag);
//			}
//			else if (element == s.top() && flag ==false)//for ?
//			{
//				s.pop(val);
//				linestream >> element;
//				if (element == '>' )
//				{
//					s.pop(val);
//				}
//			}
//		}
//		if (s.IsEmpty())//error if stack not empty
//		{
//			cout << "\nNo Error Found in line : " << lines << endl;
//		}
//		else
//			cout << "\nError Found in line :" << lines << endl;
//	}
//	//------------------------------------------------------------------------
//	void Attribute(bool &f)//attribute function   O(1)
//	{
//		if (element == s.top() && f==true)
//		{
//			cout << "Attributes closing \t";
//			s.pop(val);
//			f = false;
//		}
//		else if(element=='"'||element=='\'')
//		{
//			cout << "Attributes opening\t";
//			s.push(element);
//			f = true;
//		}
//	}	
//	//------------------------------------------------------------------------
//	void comment(string line)//comment function   O(n)
//	{
//		stringstream linestream(line);
//		cout << "Comment found here\t";
//		linestream >> element;
//		linestream >> element;
//		s.push(element);
//		linestream >> element;
//		if (element == '-')
//		{
//			s.push(element);
//			linestream >> element;
//			if (element == '-')
//			{
//				s.push(element);
//				while (linestream >> element)
//				{
//					if (element == s.top())
//					{
//						s.pop(val);
//						linestream >> element;
//						if (element == s.top())
//						{
//							s.pop(val);
//							s.pop(val);
//							linestream >> element;
//							if (element == '>')
//							{
//								s.pop(val);
//							}
//						}
//					}
//				}
//			}
//		}
//		if (s.IsEmpty())//error if stack not empty
//		{
//			cout << "\nNo Error Found in line : " << lines << endl;
//		}
//		else
//			cout << "\nError Found in line :" << lines << endl;
//	
//	}
//};
//
//
//int main()
//{
//	XML<char> xmll;
//	xmll.fun();
//	return 0;
//}