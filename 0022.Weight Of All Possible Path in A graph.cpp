/*
	This Program is for finding weight of all possible path available between any two given vertices
*/
#include<iostream>
#include<vector>
#define PII pair<int,int> 
using namespace std;

vector < PII > adj[20];//array of vector of PII type to represent a graph
bool visited[20] = {0};//boolean array to mark visited node
int v,e;
int start,end;
vector <int> w;//vector of int type to store weight of each path

void dfs(int i, int weight)//dfs logic
{
	visited[i]=true;//marking i as visited
	for(int j=0;j<adj[i].size();j++)
	{
		if(adj[i][j].second == end)//if end is neighbour of i , then we found a path
		{
			w.push_back(weight+adj[i][j].first);//push_back the weight of visiting end in the vector
			continue;//don't visit it , just go to next iteration
		}
		if(visited[adj[i][j].second]==false)//if neighbour is not visited visit it with the total distance of its from the sorce
		{
			dfs(adj[i][j].second, weight+adj[i][j].first);
		}
	}
	visited[i]=false;//unvisit the vertex i while backtracking to find all possible path, so that we can reuse the visited array
}

int main()
{
	cout<<"enter number of vertices and edges : ";
	cin>>v>>e;
	cout<<"enter the connection followed by its weight : ";
	for(int i=0; i<e;i++)//representing weighted directed graph
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back(make_pair(w,b));
	}
	cout<<"enter the starting and ending vertex : ";
	cin>>start>>end;
	dfs(start,0);//calling dfs with distance of starting is zero
	cout<<"weight of all the possible path is : ";
	for(int i=0;i<w.size();i++)//printing the result
	{
		cout<<w[i]<<" ";
	}
}
