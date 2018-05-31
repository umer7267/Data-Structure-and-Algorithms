#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void DFSgraph(int v, bool visited[]){
		visited[v] = true;
		cout<< v << " ";
		
		list<int>::iterator i;
	    for (i = adj[v].begin(); i != adj[v].end(); i++)
	    	if (!visited[*i])
	    		DFSgraph(*i, visited);
	}
	public:
		Graph(int V){
			this->V = V;
			adj = new list<int>[V];
		}
		
		void addEdge(int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
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
		
		void DFS(int root){
			bool visited[V];
			for (int i = 0; i < V; i++)
		        visited[i] = false;
		        
		    DFSgraph(root, visited);
		}
};

int main(){
	Graph graph1(8);
	graph1.addEdge(0, 1);
	graph1.addEdge(0, 2);
	graph1.addEdge(0, 3);
	graph1.addEdge(0, 4);
	graph1.addEdge(1, 5);
	graph1.addEdge(2, 5);
	graph1.addEdge(3, 4);
	graph1.addEdge(3, 6);
	graph1.addEdge(4, 6);
	graph1.addEdge(5, 7);
	graph1.addEdge(6, 7);
	graph1.printGraph();
	cout << "Following is Depth First Traversal of the above graph (starting from vertex 0) \n\n";
	graph1.DFS(0);
	return 0;
}
