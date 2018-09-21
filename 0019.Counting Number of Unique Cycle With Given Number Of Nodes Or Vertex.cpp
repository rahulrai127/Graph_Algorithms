/*
	This program is to find number of unique cycles containg k nodes and k edges in the given graph . 
*/
#include<iostream>
#include<vector>
using namespace std;
vector <int> adj[20]; //array of vector of int type to represent graph
bool visited[20];// to mark visited nodes
int v,e;

void dfs(int ver,int start,int n,int & count)
{
	visited[ver] = true;//marking node as visited in dfs
	if(n==0)// if n is decresead to 0 then don't do further dfs and check for cycle
	{
		visited[ver] = false;	// change the node as unvisited to use it later
		for(int i=0;i<adj[ver].size();i++)	//exploring the neighbour of vertex to check does it make a cycle with the starting node
		{
			if(adj[ver][i] == start)
			{
				count++;//if yes count it
				return;
			}
		}
		return; //if no simply go back
	}

	for(int i=0;i<adj[ver].size();i++)//explore the neigbour of current vertex and if not visited visit it for dfs
	{
		if(visited[adj[ver][i]]==false)
		{
			dfs(adj[ver][i],start,n-1,count);//with a decreased in n
		}
	}
	visited[ver] = false;//mark the vertex as not visited after dfs for that vertex is over to use it again later
}

int main()
{
	cout<<"enter the number of vertices and edges : ";
	cin>>v>>e;
	
	cout<<"enter the connections : ";
	for(int i=0;i<e;i++)//representing given undirected graph
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<v;i++)//initialising our visited array as false
		visited[i]=false;
	cout<<"enter the length of the cycle : ";
	int n;
	cin>>n;
	int count = 0;
	for(int i=0;i<v-(n-1);i++)//calling dfs one by one from 0 to v-(n-1) because after that there can't be any cycle with n nodes and edges.
	{
		dfs(i,i,n-1,count);
		visited[i] = true;//all the cycles from i is explored and now if  any cycle contain i then it is not unique.
	}
	count/=2;//as we are counting each cycle twice, onces clockwise and one anti-clockwise.
	cout<<endl<<"number of desired cycle : "<<count;//printing the result.
}
