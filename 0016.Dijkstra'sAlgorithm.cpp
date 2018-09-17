/*
	This algorithm is to find shortest path of a node from the source node using Dijkstra's Algorithm , assuming that there is no negative cycle
*/
#include<iostream>
#include<vector>
#include<queue>
#define PII pair<int,int> 
using namespace std;
int main()
{
	int v,e;
	cout<<"enter the number of vertices and edges : ";
	cin>>v>>e;
	vector< PII > adj[v]; // array of vector of PII type to represent given weighted graph
	int dist[v]; // int array to store distance of each node from source vertex
	bool visited[v];// boolean array to mark visited node
	for(int i=0;i<e;i++)//representing undirected weighted graph
	{
		int x,y,weight;
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));
	}
	for(int i=0;i<v;i++)//initialising the visited and distance array
	{
		visited[i]=false;
		dist[i]=INT_MAX;
	}
	priority_queue< PII ,vector<PII>,greater<PII> > q; //priority queue
	cout<<"enter the starting node : "; 
	int x;
	cin>>x;
	PII top;//variable of PII type to store top of priority queue 
	dist[x]=0;//distance of starting vertex as 0
	q.push(make_pair(0,x));//pushing the starting node to priority queue
	while(!q.empty()) //till the queue is empty
	{
		top = q.top();//top of priority queue
		q.pop();//removing top of priority queue
		int x = top.second;//current node
		int weight = top.first;//weight of current node
		if(visited[x]==false)//if current node is not visited
		{
			visited[x]=true;//visit it
			for(int i=0;i<adj[x].size();i++) //exploring the neighbour of current node
			{
				if(dist[x]+adj[x][i].first<dist[adj[x][i].second])// if distance of current node + weight of neighbour < distance of neigbour
				{
					dist[adj[x][i].second]=dist[x]+adj[x][i].first;//update the distance 
					q.push(make_pair(dist[adj[x][i].second],adj[x][i].second));//push the neighbour and its updated weight to th epriority queue
				}
			}
		}
	}
	cout<<"the distance of each node from the source vertex is : ";
	for(int i=0;i<v;i++)//printing the distance of each node from the source vertex
		cout<<dist[i]<<" ";
}

