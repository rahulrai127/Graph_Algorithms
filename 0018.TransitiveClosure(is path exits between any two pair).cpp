/*
	This program is for making transitive closure of a given graph , ie , finding all the possible pair (u,v) such that there is a path from u to v
*/
#include<iostream>
#include<vector>
#define vc vector<int>
using namespace std;

vc adj[10];//array of vector to represent directed graph
bool matrix[10][10];//matrix to represent transitive closure of the given graph
int v,e;

void initialise() //initilising transitive closure matrix of the given graph
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			matrix[i][j]=false;
		}
	}
}

void dfs(int u ,int v)	//dfs logic
{
	matrix[u][v]=true;	//marking that there is a path from u to v
	for(int i=0;i<adj[v].size();i++)	//exploring recursively the nodes reachable from v
	{
		if(matrix[u][adj[v][i]] == false)
		{
			dfs(u,adj[v][i]);
		}
	}
}

int main()
{
	cout<<"enter the number vertices and edges : ";
	cin>>v>>e;
	cout<<"enter the connections : "<<endl;
	for(int i=0;i<e;i++)//representing directed graph
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	initialise();//initialising the transitive closure matrix
	
	for(int i=0;i<v;i++)
	{
		dfs(i,i);//since the vertex is always reachable from itself
	}
	
	cout<<"the transitive closure of the given graph is : "<<endl;
	for(int i=0;i<v;i++)//printing the transitive closure matrix
	{
		for(int j=0;j<v;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
