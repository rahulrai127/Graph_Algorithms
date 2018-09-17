/*
	This program is to find the topological sorted order of a Directed Acyclic Graph
*/
#include<iostream>
#include<vector>
#include<stack>
#define ll longlong
#define vc vector<int>
using namespace std;

stack <int> s;//stack
vc adj[10];//array of vector to represent graph
bool visited[10];//boolean array to mark visited nodes

void initialise() //marking all nodes as visited 
{
	for(int i=0;i<10;i++)
		visited[i]=false;
}
void dfs(int i) //dfs logic
{
	visited[i]=true;//mark i as visited
	cout<<i<<"-->>";//print i in dfs order
	for(int j=0;j<adj[i].size();j++) //exploring neighbour of i
	{
		if(visited[adj[i][j]]==false)//if neighbour of i is unvisited recursively call the dfs logic again
		{
			dfs(adj[i][j]);
		}
	}
	s.push(i);//push i to the stack
}
int main()
{
	cout<<"enter the number of nodes and vertices : ";
	int v,e;
	cin>>v>>e;
	cout<<"enter the connectios : ";
	for(int i=0;i<e;i++)//representing Directed Acyclic Graph
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	initialise();//initialising visited array
	for(int i=0;i<v;i++)//calling dfs
	{
		if(visited[i]==false)
		{
			dfs(i);	
		}	
	}
	cout<<endl;
	while(!s.empty())//printing topological order( ie , the stack)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
