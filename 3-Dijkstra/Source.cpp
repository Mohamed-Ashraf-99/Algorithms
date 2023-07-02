#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class GraphEdge;

class GraphNode
{
public:
	GraphNode(int id, int totalCost)
	{
		Id = id;
		TotalCost = totalCost;
	}

	int Id;
	int TotalCost;
	vector<GraphEdge*> Edges;
};

class GraphEdge
{
public:
	GraphEdge(int cost, GraphNode * from, GraphNode * to)
	{
		Cost = cost;
		From = from;
		To = to;
		from->Edges.push_back(this);
	}

	int Cost;
	GraphNode* From;
	GraphNode* To;
};


void Dijkstra(vector<GraphNode*> graph)
{
	queue<GraphNode*> q;
	for (int i = 0; i < graph.size(); i++)
	{
		q.push(graph[i]);
	}

	while (q.size())
	{
		GraphNode* node = q.front();
		q.pop();

		for (int i = 0; i < node->Edges.size(); i++)
		{
			GraphNode* to = node->Edges[i]->To;
			if (node->TotalCost + node->Edges[i]->Cost < to->TotalCost)
			{
				to->TotalCost = node->TotalCost + node->Edges[i]->Cost;
			}
		}
	}
}


void main()
{
	GraphNode* n1 = new GraphNode(1, 0);
	GraphNode* n2 = new GraphNode(2, INT_MAX);
	GraphNode* n3 = new GraphNode(3, INT_MAX);
	GraphNode* n4 = new GraphNode(4, INT_MAX);
	GraphNode* n5 = new GraphNode(5, INT_MAX);
	GraphNode* n6 = new GraphNode(6, INT_MAX);

	GraphEdge* e16 = new GraphEdge(14, n1, n6);
	GraphEdge* e13 = new GraphEdge(9, n1, n3);
	GraphEdge* e12 = new GraphEdge(7, n1, n2);

	GraphEdge* e21 = new GraphEdge(7, n2, n1);
	GraphEdge* e23 = new GraphEdge(10, n2, n3);
	GraphEdge* e24 = new GraphEdge(15, n2, n4);

	GraphEdge* e31 = new GraphEdge(9, n3,n1);
	GraphEdge* e32 = new GraphEdge(10, n3, n2);
	GraphEdge* e34 = new GraphEdge(11, n3, n4);
	GraphEdge* e36 = new GraphEdge(2, n3, n6);

	GraphEdge* e45 = new GraphEdge(6, n4, n5);
	GraphEdge* e43 = new GraphEdge(11, n4, n3);
	GraphEdge* e42 = new GraphEdge(15, n4, n2);

	GraphEdge* e56 = new GraphEdge(9, n5, n6);
	GraphEdge* e54 = new GraphEdge(6, n5, n4);

	GraphEdge* e61 = new GraphEdge(14, n6, n1);
	GraphEdge* e63 = new GraphEdge(2, n6, n3);
	GraphEdge* e65 = new GraphEdge(9, n6, n5);

	vector<GraphNode*> graph;
	graph.push_back(n1);
	graph.push_back(n2);
	graph.push_back(n3);
	graph.push_back(n4);
	graph.push_back(n5);
	graph.push_back(n6);

	Dijkstra(graph);

	cout << "Done" << endl;
}
