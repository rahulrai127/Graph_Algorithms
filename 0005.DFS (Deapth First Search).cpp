/*
	This program is for Deapth First Search(DFS) Traversal in a given graphWhich we will be using in later codes for various implementation
*/
#include<iostream>
#include<vector>
#define ll longlong //macros
#define vc vector<int>//macros
using namespace std;

vc adj[10]; //array of vectors of integer type
bool visited[10]; //boolean array to mark visited nodes

void initialise() //function to initialising all nodes as unvisited
{
	for(int i=0;i<10;i++)
		visited[i]=false;
}
void dfs(int i) //function to performe dfs
{
	visited[i]=true; //marking i as visited
	cout<<i<<"-->>"; //printing the visiting node
	for(int j=0;j<adj[i].size();j++) //finding the unvisited neibour of currently visited node
	{
		if(visited[adj[i][j]]==false)
		{
			dfs(adj[i][j]);//recursively calling dfs for unvisited neighbours of current node 
		}
	}
}
int main()
{
	cout<<"enter the number of nodes and vertices : ";
	int v,e;
	cin>>v>>e;
	cout<<"enter the connectios : ";
	for(int i=0;i<e;i++) //representing graph in adjency list format
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	initialise();//calling function
	int t;
	cout<<"enter the starting node : ";
	cin>>t
	dfs(t);//calling function
}
