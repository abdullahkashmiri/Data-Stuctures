//#include<iostream>
//#include<List>
//using namespace std;
//class Graph
//{
//	int v; // No. of vertices
//	list< int>*adj; // adjacency lists
//public:
//	Graph(int n) // Constructor
//	{
//		v = n;
//		adj = new list<int>[v];
//	}
//	void TakeInput(int n, int w) // to take input from the user in this sequence: number of nodes, what are the neighbors of vertex 0, what are the neighbors of vertex 1, ... so on.
//	{
//		adj[n].push_back(w);
//	}		
//	void print()
//	{
//		cout << "Printing GRAPH" << endl;
//		for (int i = 0; i < v; i++)
//		{
//			cout << i << "-->";
//			for (auto it : adj[i])
//			{
//				cout << it << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//	void ExploreFunction(int start) // print the paths from start to every other vertex as generated by the dfs method.One path per line.
//	{
//		bool * visit = new bool[v];
//		for (int i = 0; i < v; i++)
//		{
//			visit[i] = false;
//		}
//		ExploreFunction(start, visit);
//		cout << endl;
//	}
//	void ExploreFunction(int start, bool visit[])
//	{
//		visit[start] = true;
//		cout << start << "  ";
//		list<int>::iterator it;
//		for (it = adj[start].begin(); it != adj[start].end(); it++)
//		{
//			if (!visit[*it])
//				ExploreFunction(*it, visit);
//		}
//	}
//};
//int main()
//{
//	Graph g(4); // Total 5 vertices in graph
//	cout << "INSERTION" << endl;
//	g.TakeInput(0, 1);
//	g.TakeInput(0, 2);
//	g.TakeInput(1, 2);
//	g.TakeInput(2, 0);
//	g.TakeInput(2, 3);
//	g.TakeInput(3, 3); 
//	g.print();
//
//	cout <<"Following is Depth First Traversal\n";
//	cout << "For N = 1 : " << endl;
//	g.ExploreFunction(1);
//	cout << "For N = 2 : " << endl;
//	g.ExploreFunction(2);
//
//	//Sample output of explore function for starting from vertex 2.
//	//2 0
//	//2 0 1
//	//2 0 1 3
//	//*********
//	//Sample output of explore function for starting from vertex 1.
//	//1 2
//	// 1 2 0
//	//1 2 0 3
//	cout << endl << "Program Terminated Successfully" << endl;
//	system("pause");
//	return 0;
//}