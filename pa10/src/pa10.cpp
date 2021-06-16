//============================================================================
// Name        : pa10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Vertex
{
	int vertexValue;
	bool visited;
	vector <int> neighbors;
};

class Graph {
public:
	Graph();

	void buildGraph(vector<Vertex> &graph);
	void dft(vector <Vertex> &graph);
	void bft(vector <Vertex> &graph);

	virtual ~Graph();
private:
	void dftInternal(vector <Vertex> &graph, int vertex);
	int vertexLookup (vector<Vertex> &graph, int data);

};




int main() {
	Graph a;
	vector <Vertex> x;
	cout<<"Populated graph : "<<endl<<endl;
	a.buildGraph(x);
	cout<<endl<<endl;
	cout<<"Depth-first traversal : "<<endl<<endl;
	a.dft(x);
	cout<<endl<<endl;
	cout<<"Breadth-first traversal : "<<endl<<endl;
	a.bft(x);
	cout<<endl<<endl;
	cout<<"Have a great day!";
	return 0;
}

Graph::Graph() {
	// TODO Auto-generated constructor stub

}

void Graph::buildGraph(vector <Vertex> &graph)
{
	ifstream infile;
	infile.open("./src/pa10.txt");
	if (!infile)
	{
		cerr << " Sorry, unable to open file" << endl;
		exit (1);
	}
	int data, i = 0;
	Vertex temp;
	while (infile >> data)
	{
		temp.vertexValue = data;
		cout << "Vertex number " << i << " value "<< data << " neighbors-> ";
		graph.push_back(temp);
		infile >> data;
		while(data != -1)
		{
			cout << data << " " << flush;
			graph[i].neighbors.push_back(data);
			infile >> data;
		}
		cout << endl;
		i++;
	}
	infile.close();
}

int Graph::vertexLookup(vector<Vertex> &graph, int data)
{
	for(unsigned int i = 0; i < graph.size(); i++)
		{
			if(graph[i].vertexValue == data)
			{
				return i;
			}
		}
	return -1;

}

void Graph::dft(vector<Vertex> &graph)
{
	//cout << "Beginning of dft\n";
	if (graph.empty())
		return;
	for(unsigned int i = 0; i < graph.size(); i++)
		graph[i].visited = false;
	int current = 0;
	while(current != graph.size())
	{
		//cout << "In while of dft\n";
		if (graph[current].visited == false)
		{
			//cout << "In if of dft\n";
			dftInternal(graph,current);
		}
		current++;
	}
	//cout << "End of dft\n";
}
void Graph::dftInternal(vector <Vertex> &graph, int vertex)
{
	//cout<<"visiting"<<endl;
	cout << graph[vertex].vertexValue << " ";
	graph[vertex].visited = true;
	if (!graph[vertex].neighbors.empty())
	{
		int position = 0;
		if (position == -1)
			cout << "Error position cannot be found..\n";
		for (unsigned int i = 0; i < graph[vertex].neighbors.size(); i++)
		{
			if (!graph[graph[vertex].neighbors[i]].visited)
				dftInternal(graph,graph[vertex].neighbors[i]);
		}
	}

}
void Graph::bft(vector<Vertex> &graph) {
	queue <Vertex> a;
	for(unsigned int i = 0; i<graph.size(); i++)
		{
			graph[i].visited = false;
		}
	a.push(graph[0]);
	graph[0].visited = true;
	for(unsigned int i = 1; i<graph.size(); i++)
	{
		if(graph[i].visited != true)
		{
			a.push(graph[i]);
			graph[i].visited = true;
			while(!a.empty())
			{
				cout<<a.front().vertexValue<<" ";
				int j = vertexLookup(graph, a.front().vertexValue);
				a.pop();
				for(unsigned int k = 0; k<graph[j].neighbors.size(); k++)
				{
					int n = vertexLookup(graph, graph[j].neighbors[k]);
					if(graph[n].visited != true)
					{
						a.push(graph[n]);
						graph[n].visited = true;
					}
				}
			}
		}
	}
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

