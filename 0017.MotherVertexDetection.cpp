/*
	This program is for finding that is mother vertex exists in the given directed and connected graph , if yes found one of them.
*/
#include<iostream>
#include<vector>
#define ll longlong //macros
#define vc vector<int>//macros
using namespace std;


vc adj[10]; //array of vectors of integer type
bool visited[10]; //boolean array to mark visited nodes
int temp = 0;//to store the mother vertex

void initialise() //function to initialising all nodes as unvisited
{
	for(int i=0;i<10;i++)
		visited[i]=false;
}
void dfs(int i) //function to performe dfs
{
	visited[i]=true; //marking i as visited
	for(int j=0;j<adj[i].size();j++) //finding the unvisited neibour of currently visited node
	{
		if(visited[adj[i][j]]==false)
		{
			dfs(adj[i][j]);//recursively calling dfs for unvisited neighbours of current node 
		}
	}
	
	temp = i;//marking the last completed bfs call
}
int main()
{
	cout<<"enter the number of nodes and vertices : ";
	int v,e;
	cin>>v>>e;
	cout<<"enter the connectios : ";
	for(int i=0;i<e;i++) //representing directed graph in adjency list format
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	initialise();//calling function
	
	for(int i=0;i<v;i++)//performing bfs
	{
		if(visited[i]==false)
		{
			dfs(i);
		}
	}
	
	initialise();//intialising visited array again
	dfs(temp);//performing dfs as temp as starting node
	for(int i=0;i<v;i++)//checking if any node is unvisited
		if(visited[i]==false)
			temp = -1;
	if(temp == -1)//if any node is unvisited then no mother vertex
		cout<<endl<<"mother vertex doesnot exists..!!";
	else//if all the node is visited then the last completed dfs node is one of the mother node
		cout<<endl<<"mother vertex is : "<<temp;
}
