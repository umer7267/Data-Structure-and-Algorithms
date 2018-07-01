#include<iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;   
public:
    Graph(int V)
    {
	    this->V = V;
	    adj = new list<int>[V];
	}
 
    void addEdge(int v, int w)
	{
    	adj[v].push_back(w);
    	adj[w].push_back(v);
	}
	
	void printGraph(){
		list<int>::iterator v;
		for(int i=0; i<V; i++){
			cout << "\n Adjacency list of vertex "<< i << "\n head ";
			for(v = adj[i].begin(); v != adj[i].end(); v++){
				cout << " -> " << *v;
			}
			cout<<"\n";
		}
		cout<<"\n\n";
	}

    void BFS(int s)
    {
	    bool *visited = new bool[V];
	    for(int i = 0; i < V; i++)
	        visited[i] = false;
	
	    list<int> queue;
	 
	    visited[s] = true;
	    queue.push_back(s);
	 
	    list<int>::iterator i;
	 
	    while(!queue.empty())
	    {
	        s = queue.front();
	        cout << s << " ";
	        queue.pop_front();
	 
	        for (i = adj[s].begin(); i != adj[s].end(); ++i)
	        {
	            if (!visited[*i])
	            {
	                visited[*i] = true;
	                queue.push_back(*i);
	            }
	        }
    	}
	}
};
 
int main()
{
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
 	
 	g.printGraph();
    cout << "Following is Breadth First Traversal " << "(starting from vertex 0) \n";
    g.BFS(0);
 
    return 0;
}
