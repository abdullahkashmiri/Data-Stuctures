//#include<iostream>
//#include<sstream>
//#include<time.h>
//
//#include<SFML/Graphics.hpp>
//#include<SFML/System.hpp>
//#include<SFML/Window.hpp>
//#include<SFML/Audio.hpp>
//#include<SFML/audio.hpp>
//
//using namespace std;
//using namespace sf;
//
//template< class T>
//class Node//node class
//{
//public:
//	T data;
//	Node* next;
//	Node()//default constructor
//	{
//		this->data = NULL;
//		this->next = NULL;
//	}
//	Node(T data)//overloaded constructor
//	{
//		this->data = data;
//		this->next = NULL;
//	}
//};
//
//template<class T>
//class Queue//Class QUeue
//{
//private:
//	Node<T>* front;
//	Node<T>* rear;
//	int size;
//public:
//	Queue()//default constructor
//	{
//		this->front = NULL;
//		this->rear = NULL;
//		this->size = 0;
//	}
//	void EnQueue(T data)// Insertion
//	{
//		Node<T>* newnode = new Node<T>(data);
//		if (this->rear == NULL)// if queue is empty
//		{
//			this->rear = newnode;
//			this->front = newnode;
//		}
//		else if (this->rear != NULL)// if queue has some nodes already
//		{
//			this->rear->next = newnode;
//			this->rear = this->rear->next;
//		}
//		this->size++;
//	}
//	T DeQueue()//pop function
//	{
//		if (!isEmpty())// has elements
//		{
//			T data = this->front->data;
//			Node<T>* temp = this->front;//saving index
//			this->front = this->front->next;
//			delete temp;//deleting index
//			this->size--;
//			return data;
//		}
//		return NULL;
//	}
//	int Size()//getting size
//	{
//		return this->size;
//	}
//	bool isEmpty()//checking queue
//	{
//		if (this->size == 0)
//		{
//			cout << "Empty Queue!" << endl;
//			front = rear = NULL;
//			return true;
//		}
//		return false;
//	}
//	void Print()//printing queue
//	{
//		Node<T>* current = front;
//		cout << "Queue is : ";
//		while (current != NULL)
//		{
//			cout << current->data << ",";
//			current = current->next;
//		}
//		cout << endl;
//	}
//	T Front()//checking fornt elemet
//	{
//		if (!isEmpty())
//		{
//			return front->data;
//		}
//	}
//};
//template<class T>
//class Display :public Queue<T>//Display Queue
//{
//private:
//	Queue<T> Q;//priavte variables for logic
//	int Qsize;
//	int skip;
//	int execute;
//	int midx;
//	int midy;
//	RenderWindow* window;//private variable for sfml
//	Event event;
//	VideoMode videomode;
//	Font font;
//	Text Cexe;
//	Text surviour;
//	Text start;
//	Text *s;
//	Vector2f direction;
//	Texture alive;
//	Texture dead;
//	Sprite* soilder;
//	//privateFunctions
//	void initVariables(int qs, int k)//initillizing variables
//	{
//		this->Qsize = qs;
//		this->skip = k;
//		this->execute = 0;
//		this->midx = 10;
//		this->midy = 50;
//		soilder = new Sprite[Qsize];
//		s = new Text[Qsize];
//		this->window = NULL;
//		this->initFonts();
//		this->initTextures();
//		this->initsprite(alive);
//		//cout << "Variables Initillized" << endl;
//	}
//	void initWindow()//initillizing window size
//	{
//		this->videomode.height = 1000;
//		this->videomode.width = 1280;
//		this->window = new RenderWindow(videomode, "Josephus Algorithm", Style::Titlebar | Style::Close);
//		this->window->setFramerateLimit(60);
//	//	cout << "Window Initillized" << endl;
//	}
//	void initFonts()//initillinzing fonts
//	{
//		if (!this->font.loadFromFile("fonts/fontacme.ttf"))//loading fonts
//		{
//			cout << "Unable to Load Fonts." << endl;
//		}
//		this->Cexe.setFont(this->font);//ececution number display fonts
//		this->Cexe.setCharacterSize(24);
//		this->Cexe.setFillColor(Color::White);
//		this->Cexe.setString("Current Execution : ");
//		this->Cexe.setPosition(300, 15);
//		this->surviour.setFont(this->font);//surviour number display fonts
//		this->surviour.setCharacterSize(80);
//		this->surviour.setFillColor(Color::Red);
//		this->surviour.setString("SURVIVOUR SOILDER NO : ");
//		this->surviour.setPosition(200, 400);
//		this->start.setFont(this->font);//starting display fonts
//		this->start.setCharacterSize(80);
//		this->start.setFillColor(Color::Red);
//		this->start.setString("JOSEPHUS ALGORITHM");
//		this->start.setPosition(230, 495);
//		for (int i = 0; i < Qsize; i++)//setting fonts for all soilder numbers
//		{
//			this->s[i].setFont(this->font);
//			this->s[i].setCharacterSize(24);
//			this->s[i].setFillColor(Color::White);
//			this->s[i].setString("S_no:");
//		}
//		//cout << "Fonts Initillized" << endl;
//	}
//	void initTextures()//setting textures
//	{
//		if (!this->alive.loadFromFile("res/soilder.png"))//alive soilder
//		{
//			cout << "Unable to Load Texture" << endl;
//			system("pause");
//		}
//		if (!this->dead.loadFromFile("res/dead3.png"))//dead soilder
//		{
//			cout << "Unable to Load Texture" << endl;
//			system("pause");
//		}
//		else
//			cout << "Sprite texture successfully loaded" << endl;
//	}
//	void initsprite(Texture& texture)//making sprites
//	{
//		for (int i = 0; i < Qsize; i++)//setting all alive
//		{
//			this->soilder[i].setTexture(texture);
//			this->soilder[i].scale(0.07f, 0.07f);
//		}
//	//	cout << "Sprites Loaded" << endl;
//	}
//public:
//	Display()//default constructior
//	{
//		this->initVariables(0, 0);
//		this->initWindow();
//		this->Algorithm_Initillization();
//		//cout << "Default Constructor" << endl;
//	}
//	Display(int n, int k)//overloaded constructor
//	{
//		this->initVariables(n, k);
//		this->initWindow();
//		this->Algorithm_Initillization();
//		//cout << "Overloaded Constructor" << endl;
//	}
//	~Display()//destructor
//	{
//		delete this->window;
//		delete[]this->soilder;
//		cout << "Desrtructor" << endl;
//	}
//	void Algorithm_Initillization()//initillizing logic here i.e Queue
//	{
//		for (int i = 0; i < Qsize; i++)
//		{
//			Q.EnQueue(i + 1);
//		}
//		Q.Print();
//	//	cout << "Algorithm Initillization" << endl;
//	}
//	void Josephus_Algorithm()//algorithm logic here killing soilders after k-1 soilders
//	{
//	//	cout << "Current Size : " << Q.Size() << endl;;
//		T data;
//		for (int i = 0; i < this->skip - 1; i++)//killing after k-1
//		{
//			data = Q.DeQueue();
//			Q.EnQueue(data);
//		}
//		data = Q.DeQueue();
//		execute = data;
//		this->update_Soilder_live(execute);//fun to update texture
//	//	cout << "Soilder Executed :(  : " << execute << endl;
//	//	cout << "Josephus Algorithm " << endl;
//	}
//	void Updated_Display()//function for Displaying 
//	{
//	//	Q.Print();
//		for (int i = 0, j = 0, k = 0; k < Qsize; i++, k++)
//		{
//			if (i == 15)//max soilders in a row
//			{
//				i = 0;
//				j++;
//			}
//			this->soilder[k].setPosition(i * 85 + midx, j * 90 + midy);//placing soilders
//			s[k].setPosition(i * 84 + midx+ 40, j * 90 + midy + 50);//placing numbers
//		}
//	//	Q.Print();
//	//	cout << "Updated Display" << endl;
//	}
//	void update_Soilder_live(int n)//setting dead texture 
//	{
//		this->soilder[n - 1].setTexture(dead);
//		this->soilder[n - 1].scale(1.f, 1.f);
//	}
//	bool Running()//while window is open
//	{
//		return this->window->isOpen();
//	//	cout << "Program Running" << endl;
//	}
//	void renderText(RenderTarget& Target)//displaying texture
//	{
//		Target.draw(this->Cexe);//execution line
//		for (int i = 0; i < Qsize; i++)//number of soilders
//		{
//			Texture const *temp = soilder[i].getTexture();
//			if (temp == &alive)
//				Target.draw(this->s[i]);
//		}
//	//	cout << "Text Rendering" << endl;
//	}
//	void updateText()//text updating
//	{
//		stringstream s1, s2, s3;
//		s1 << "Current Soilder Execution : " << this->execute<<"\t\t Soilders Left : "<<Q.Size()<<"\t\t Skip Rate : "<<skip;
//		this->Cexe.setString(s1.str());
//		s2 << "SURVIVOUR SOILDER NO : " << this->Q.Front();//end screen
//		this->surviour.setString(s2.str());
//		s3 << "JOSEPHUS ALGORITHM";//start screen
//		this->start.setString(s3.str());
//		for (int i = 0; i < Qsize; i++)
//		{
//			stringstream s4;
//			s4 << i + 1;
//			this->s[i].setString(s4.str());
//		}
//	//	cout << "Text Updated" << endl;
//	}
//	void PollEvents()//while window is open
//	{
//		while (this->window->pollEvent(this->event))
//		{
//			if (this->event.type == Event::Closed)//closed
//			{
//				this->window->close();
//				break;
//			}
//			if (this->event.type == Event::KeyPressed && this->event.key.code == Keyboard::Escape)//escape key
//			{
//				this->window->close();
//				break;
//			}
//		}
//	}
//	void update(bool& flag)//update function for all sfml
//	{
//		this->PollEvents();
//		if (Q.Size() > 1)//continue till only one soilder remains
//		{
//			this->Updated_Display();
//			this->Josephus_Algorithm();
//		}
//		else if (Q.Size() == 1)//if one soilder exit
//		{
//			cout << "Soldier no " << Q.Front() << " survivied" << endl;
//			flag = false;
//		}
//		this->updateText();
//	}
//	void rendersprite(RenderWindow& target)//displaing all soilders
//	{
//		for (int i = 0; i < Qsize; i++)
//		{
//			target.draw(this->soilder[i]);
//		}
//	//	cout << "Render Sprite" << endl;
//	}
//	void render()//render function  for all sfml
//	{
//		this->window->clear();
//		this->renderText(*this->window);
//		this->rendersprite(*this->window);
//		this->window->display();
//	}
//	void START()//start display
//	{
//		this->window->clear();
//		this->window->draw(this->start);
//		this->window->display();
//	}
//	void END()//end display
//	{
//		this->window->clear();
//		this->window->draw(this->surviour);
//		this->window->display();
//	}
//};
//void delay(int number_of_seconds)//delay function 
//{
//	int milli_seconds = 1000 * number_of_seconds;
//	clock_t start_time = clock();
//	while (clock() < start_time + milli_seconds)
//		;
//}
//int main()
//{
//	int k, n;
//	cout << "Enter Number of Soilders : ";
//	cin >> n;
//	cout << "How many Soilders you want to skip each time : ";
//	cin >> k;
//	bool flag = true;
//	Display<int> D(n, k);
//	D.START();
//	delay(3);
//	while (D.Running() && flag)
//	{
//		D.update(flag);
//		D.render();
//		//delay(1);
//		if (flag == false)
//		{
//			cout << "Press Enter to EXIT" << endl;
//			delay(3);
//			D.END();
//			system("pause");
//		}
//		system("pause");
//	}
//	return 0;
//}