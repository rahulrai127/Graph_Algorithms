/*
	This program is for Breadth First Search (BFS) Traversal in a Graph, for which we will see various application in upcoming codes.
*/
#include<iostream>
#include<vector>
#include<queue>
#define vc vector<int> // macro to represent "vector <int> " as "vc"
using namespace std;
int main()
{
	cout<<"enter the number of nodes and edges : ";
	int v,e;
	cin>>v>>e;
	vc adj[v]; // array of vector of integer type
	bool visited[v]={0}; //boolean array to mark visited nodes
	cout<<"enter the connections :";
	int a,b;
	for(int i=0;i<e;i++) // creating adjency list representation of graph
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<"enter the starting node number : ";
	int t;
	cin>>t; // starting node for BFS traversal
	queue<int> q; //queue
	q.push(t); //pushing the first node to the queue
	visited[t]=true; //marking the first node as visited
	while(!q.empty()) // Breadth First Traversal until the queue is empty
	{
		int top = q.front(); //taking the top element from queue in FIFO manner
		q.pop();//removing the top element from the queue in FIFO manner
		for(int i=0;i<adj[top].size();i++) 
		{
			if(visited[adj[top][i]]==false)
			{
				visited[adj[top][i]]=true; // marking all unvisited adjecent of top nodes as visited
				q.push(adj[top][i]);//pushing all unvisited adjacent of top nodes to the queue
				cout<<adj[top][i]<<"--->>"; //displaying the node, as we just visited the node
			}
		}
	}
}
