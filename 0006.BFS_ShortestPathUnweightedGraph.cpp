/*
	This program is find shortest path in an unweighted graph
*/
#include<iostream>
#include<vector>
#include<queue>
#define vc vector<int>
using namespace std;
int main()
{
	cout<<"enter the number of nodes and edges : ";
	int v,e;
	cin>>v>>e;
	vc adj[v]; //array of vector
	bool visited[v]={0}; //bool array to mark visited node
	int distance[v];//int array to store distance of node from source vertex
	for(int i=0;i<v;i++)//initialising distance as -1
		distance[i]=-1;
	cout<<"enter the connections :";
	int a,b;
	for(int i=0;i<e;i++)//creating graph
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<"enter the starting node number : ";
	int t;
	cin>>t;
	distance[t]=0;//starting distance as 0
	queue<int> q;//queue for bfs
	q.push(t);//pushing first element to queue
	visited[t]=true;//marking first element as visited
	while(!q.empty())//till queue is not empty (BFS logic)
	{
		int top = q.front(); //taking out the top element
		q.pop();//removing the top element
		for(int i=0;i<adj[top].size();i++)//exploring neioubobur of top
		{
			if(visited[adj[top][i]]==false) //visiting unvisited neighbour of top
			{
				visited[adj[top][i]]=true; //marking unvisited node as visited
				q.push(adj[top][i]);//pushing unvisited node to the queue
				cout<<adj[top][i]<<"--->>";//printing
				distance[adj[top][i]]=distance[top]+1; //distance of the visited node from root node
			}
		}
	}
	cout<<endl;
	for(int i=0;i<v;i++)//printing the distance of each node from root node.
	{
		cout<<distance[i]<<" ";
	}
}
