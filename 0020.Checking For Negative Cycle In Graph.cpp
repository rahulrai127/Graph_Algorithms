/*
	This algorithm is to find , is there any negative cycle in the graph using Bellman Ford's Algorithm.
*/

#include<iostream>
#include<vector>
#define PII pair<int,int>
using namespace std;
int main()
{
	cout<<"enter the number of vertices and edges : ";
	int v,e;
	cin>>v>>e;
	int dist[v];
	for(int i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
	}
	vector <PII > adj[v];//array of vector of PII type to represent a weighted graph
	cout<<"enter the connection followed by its weight : ";
	for(int i=0;i<e;i++)//representing weighted undirected graph
	{
		int x,y,weight;
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(y,weight));
		adj[y].push_back(make_pair(x,weight));
	}
	dist[0] = 0;//distance of first node is 0
	for(int i=0;i<v;i++)//visiting all nodes one by one
	{
		for(int j=0;j<adj[i].size();j++)// visiting all neighbour of the current node
		{
			if(dist[i]+adj[i][j].second<dist[adj[i][j].first])//if distance of node + edge weight < distance of neighbour 
			{
				dist[adj[i][j].first] =dist[i]+adj[i][j].second; //update distance of neighbour as (node + edge weight)
			}
		}
	}
	
	bool flag = false;//to mark negative cycle exists or not
	//Performing bellman Ford onces again
	for(int i=0;i<v;i++)//visiting all nodes one by one
	{
		for(int j=0;j<adj[i].size();j++)// visiting all neighbour of the current node
		{
			if(dist[i]+adj[i][j].second<dist[adj[i][j].first])//if distance of node + edge weight < distance of neighbour 
			{
				dist[adj[i][j].first] =dist[i]+adj[i][j].second; //update distance of neighbour as (node + edge weight)
				flag=true;//negative cycle exists as the distance array got updated n 2nd Bellman Ford 
			}
		}
	}
	cout<<endl;
	if(flag)
		cout<<"negative cycle found";
	else
		cout<<"negative cycle not found";
}
