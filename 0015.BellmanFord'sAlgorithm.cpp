/*
	This algorithm is to find shortest distance assuming that there is no negative cycle in the given graph
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
	cout<<"the distance of each node from source vertex : ";
	for(int i=0;i<v;i++)//printing the distance.
	{
		cout<<dist[i]<<" ";
	}
}
