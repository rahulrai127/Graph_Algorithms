/*
	This Program is to check , is the graph is bipartite or not..!
*/
#include<iostream>
#include<vector>
#include<queue>
#define vc vector<int>
#define it vector<int>::iterator 
using namespace std;
int main()
{
	cout<<"enter the number of nodes and edges : ";
	int v,e;
	cin>>v>>e;
	vc adj[v];//array of vector to represent graph
	int color[v];//to assign color to the nodes
	for(int i=0;i<v;i++)//initilising color as -1 for all the nodes
		color[i]=-1;
	cout<<"enter the connections :";
	int a,b;
	for(int i=0;i<e;i++)//representing graph
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	color[0]=0;//giving color 0 to initial node
	bool flag = true;//boolean variable to mark graph is bipartite or not
	for(int i=0;i<v;i++) //bipartite logic
	{
		for(int j=0;j<adj[i].size();j++) //visiting neighbour of node i
		{
			if(color[i]==0 && color[adj[i][j]]==-1) //if the parent color is 0 and neighbour is unvisited ( ie , -1) then change the neighbour's color to 1
				color[adj[i][j]]=1;
			if(color[i]==1 && color[adj[i][j]]==-1)//if the parent color is 1 and neighbour is unvisited ( ie , -1) then change the neighbour's color to 0
				color[adj[i][j]]=0;
			if(color[i]==1 && color[adj[i][j]]==1)//if the parent color is 1 and neighbour is visited with same color (ie , 1) then the graph is not bipartite
				flag=false;
			if(color[i]==0 && color[adj[i][j]]==0)//if the parent color is 0 and neighbour is visited with same color (ie , 0) then the graph is not bipartite
				flag=false;
		}
	}
	cout<<endl;
	if(flag)
		cout<<"bipartite graph detected";
	else
		cout<<"bipartite graph not detected";
}
