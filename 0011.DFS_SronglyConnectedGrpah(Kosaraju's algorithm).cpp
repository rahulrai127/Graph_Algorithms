/*
	This algorihtm is to find the strongly connected components of a given Directed graph from Kosaraju's Algorithm using 2 DFS traversal and topological sorting
*/
#include<iostream>
#include<vector>
#include<stack>
#define ll longlong
#define vc vector<int>
using namespace std;

stack <int> s; //stack
vc adj[10];//array of vector to represent a graph
vc trans[10];//array of vector to represent transpose of a graph
bool visited[10];//boolean array to mark visited nodes

void initialise() //initilising boolean array visited
{
	for(int i=0;i<10;i++)
		visited[i]=false;
}
void dfs(int i) //dfs logic for given graph
{
	visited[i]=true;
	cout<<i<<"-->>";
	for(int j=0;j<adj[i].size();j++)
	{
		if(visited[adj[i][j]]==false)
		{
			dfs(adj[i][j]);
		}
	}
	s.push(i);//storing element in stack to get the topological sorted nodes
}



void trans_dfs(int i)//dfs logic for transpose of a given graph
{
	visited[i]=true;
	cout<<i<<"-->>";
	for(int j=0;j<trans[i].size();j++)
	{
		if(visited[trans[i][j]]==false)
		{
			trans_dfs(trans[i][j]);
		}
	}
}
int main()
{
	cout<<"enter the number of nodes and vertices : ";
	int v,e;
	cin>>v>>e;
	cout<<"enter the connectios : ";
	for(int i=0;i<e;i++)//representing directed graph and its transpose
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		trans[b].push_back(a);
	}
	
	initialise();//initialising boolean array
	for(int i=0;i<v;i++) //dfs for given graph to get topological sorted array
	{
		if(visited[i]==false)
		{
			dfs(i);	
		}	
	}
	
	initialise();//initialising boolean array
	int count =0;//countingg number of connected component in the graph
	cout<<endl;
	while(!s.empty())//till the stack is not empty
	{
		int top =s.top();//taking top element of the stack
		s.pop();//removing the top element from the stack
		if(visited[top]==false)//if top element if not visited -- visit it
		{
			trans_dfs(top);//dfs in transpose of the given graph , it gives one strongly connected component from the graph
			cout<<endl;
			count++;//increasing the count of stringly connected component
		}	
	}
	cout<<"number of fully connected graph : "<<count;
}
