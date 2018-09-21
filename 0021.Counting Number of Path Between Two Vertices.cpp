/*
	This Program is for counting all possible path available between any two given vertices
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[20];	//array of vector of int type to represent a graph
bool visited[20] = {0};	//boolean array to mark visited node
int v,e;
int start, end;
int count;

void dfs(int i) //dfs logic
{
	visited[i] = true;//marking i as visited
	for(int j=0;j<adj[i].size();j++)
	{
		if(adj[i][j] == end)	//if end is neighbour of i , then we found a path
		{
			count++;//count it 
			continue;//don't visit it , just go to next iteration
		}
		if(visited[adj[i][j]] == false)//if neighbour is not visited visit it
		{
			dfs(adj[i][j]);
		}
	}
	visited[i] = false;//unvisit the vertex i while backtracking to find all possible path, so that we can reuse the visited array
}

int main()
{
	cout<<"enter the number of vertices and edges : ";
	cin>>v>>e;
	cout<<"enter the connections : ";
	for(int i=0;i<e;i++)//representing directed graph
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	cout<<"enter the starting and ending vertex : ";
	cin>>start>>end;
	count = 0;
	dfs(start);//calling dfs from start
	cout<<"Number of unique path between the given two vertices is : "<<count; //printing the result
}
