/*
	This program is to check is the given undirected - graph is cyclic or not
*/
#include<iostream>
#include<vector>
#include<queue>
#define vc vector<int>
#define it vector<int>::iterator 
using namespace std;
int main()
{
	cout<<"enter the number of nodes and edges : ";
	int v,e;
	cin>>v>>e;
	vc adj[v];	//Array of vector to represent graph
	bool visited[v]={0};	//boolean arary to mark visited nodes
	cout<<"enter the connections :";
	int a,b;
	for(int i=0;i<e;i++)	//representing graph
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<"enter the starting node number : ";
	int t;
	cin>>t;	//starting node for bfs
	queue<int> q;	//queue
	q.push(t);	//pushing first element to the queue
	visited[t]=true;//marking first element as visited
	bool flag = false;//boolean variable to mark graph has cycle or not
	while(!q.empty())	//till the queue is not empty
	{
		int top = q.front(); //first element of queue
		q.pop();	//removing first element from the queue
		for(int i=0;i<adj[top].size();i++)	//exploring the neigbour of the top 
		{
			if(visited[adj[top][i]]==false) //visiting the unvisited neighbour
			{
				int temp = adj[top][i];	//storing the neighbour in a temp variable
				visited[temp]=true;	//marking visiting node as visited
				q.push(temp);//pushing the visiting node to queue
				cout<<temp<<"--->>";//printing in BFS
				for(int j=0;j<adj[temp].size();j++)	//checking is neigbour of visiting node is already visited or not
				{
					if(visited[adj[temp][j]]==true && adj[temp][j]!=top) //neighbour of visiting node is already visited and is not its parent node then the graph is cyclic
					{
						flag=true;//marking graph is cyclic
					}
				}
			}
		}
	}
	if(flag)//if cyclic
		cout<<"cycle detected";
	else//if not cyclic
		cout<<"no cycle detected";
}
