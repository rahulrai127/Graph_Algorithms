/*
	This program is to find Minimum spanning tree using Prim's Algorithm
*/
#include<iostream>
#include<queue>
#include<vector>
#define PII pair<int,int> 
using namespace std;

vector <PII> adj[10000]; //array of vector of PII( defined in macro ) type for weighted graph
int v,e;
bool visited[10000]; //boolean array to mark visited node

void initialise() //initialising boolean array
{
	for(int i=0;i<v;i++)
		visited[i]=false;
}
int prim(int x)//prim's algorihtm logic
{
	priority_queue<PII,vector<PII>,greater<PII> > q;//priority queue
	int mincost = 0;//spanning tree cost initialised as 0
	PII top; //variable to hold top element of priority queue
	q.push(make_pair(0,x));//pushing first node to the priority queue with zero weight
	while(!q.empty())//until priority queue is empty
	{
		top=q.top();	//taking top element of priority queue
		q.pop();	//removing top element of priority queue
		x=top.second;	//node of top
		if(visited[x]==false)	//if the node is unvisited, visit it.!
		{
			mincost = mincost +top.first;	//add the cost of visiting
			visited[x]=true;	//mark it as visited
			for(int i=0;i<adj[x].size();i++)	//exploring neighbour of the visiting node
			{
				if(visited[adj[x][i].second]==false)	//if neighbour of visiting node is not visited push it to the priority queue
				{
					q.push(adj[x][i]);
				}
			}
		}
	}
	return mincost; //returning the cost of MST to main function
}

int main()
{
	cout<<"enter the number of vertices and edges : ";
	cin>>v>>e;
	cout<<"enter the connections with weights : ";
	for(int i=0;i<e;i++)//representing a given undirected weighted graph
	{
		int x,y,weight;
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));
	}
	initialise(); //initialising the visited array
	cout<<"enter the starting vertex";
	int n;
	cin>>n;
	int mincost  = prim(n);
	cout<<"the cost of MST is : "<<mincost;//printing the minimum cost of MST
}
