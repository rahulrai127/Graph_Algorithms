/*
	This algorithm to check , is there a cycle in a given directed graph using color (-1,0,1)
*/

#include<iostream>
#include<vector>
#define ll longlong
#define vc vector<int>
using namespace std;

vc adj[10]; //array of vector to represent the given graph
bool visited[10];//boolean array to mark visited nodes
int color[10];//int array to given color to the nodes  -1 -->> unvisited   0-->>in recursion stack   1-->> visited
bool flag = false;//boolean variable to mark graph is cyclic  or not

void initialise()//initialising visited,color and flag
{
	for(int i=0;i<10;i++)
	{
		visited[i]=false;
		color[i]=-1;
	}
	flag = false;
		
}
void dfs(int i)//dfs logic
{
	visited[i]=true;
	cout<<i<<"-->>";
	for(int j=0;j<adj[i].size();j++)
	{
		if(color[adj[i][j]]==0)//if neighbour of the visiting node is currently in stack , ie a back edge exsits , hence graph is cyclic
		{
			flag = true;
		}
		else if(visited[adj[i][j]]==false) //else if neighbour of visiting node is not visited, visit it
		{
			color[adj[i][j]]=0; // mark the visiting node int the stack
			dfs(adj[i][j]);//call dfs for visiting node
			color[adj[i][j]]=1;//after dfs over mark it out from the stack
		}
	}
}
int main()
{
	cout<<"enter the number of nodes and vertices : ";
	int v,e;
	cin>>v>>e;
	cout<<"enter the connectios : ";
	for(int i=0;i<e;i++)//representing directed graph
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	initialise();//initialsing visited,color and flag
	
	for(int i=0;i<v;i++) // calling dfs 
	{
		if(visited[i]==false)//if not visited call dfs
		{
			color[i]=0;// mark the visiting node int the stack
			dfs(i);//call dfs for visiting node
			color[i]=1;//after dfs over mark it out from the stack
		}
	}
	if(flag)
		cout<<"cyclic graph";
	else
		cout<<"acyclic graph";
	return 0;
}

