/*
	This Program is for print all possible path available between any two given vertices
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> adj[20];//array of vector of int type to represent a graph
bool visited[20] = {0};//boolean array to mark visited node
int v,e;
int start, end;
int count;
stack<int> s;//stack to keep track of the path

void dfs(int i)//dfs logic
{
	visited[i] = true;//marking i as visited
	for(int j=0;j<adj[i].size();j++)
	{
		if(adj[i][j] == end)//if end is neighbour of i , then we found a path and print that path
		{
			s.push(adj[i][j]);//pushing the end to the stack/path
			stack<int> path;//temporary stack to reverse our current stack
			for(stack<int> temp = s;!temp.empty();temp.pop())//reversing our current path stack
			{
				path.push(temp.top());
			}
			while(!path.empty())//printing the path or our temporary stack
			{
				cout<<path.top()<<"-->>";
				path.pop();
			}
			cout<<endl;
			s.pop();//removing the end element from the path/stack
			count++;//counting it as a path
			continue;//don't visit it , just go to next iteration
		}
		if(visited[adj[i][j]] == false)//if neighbour is not visited visit it
		{
			s.push(adj[i][j]);//push the neighbour to the stack to keep track of the path
			dfs(adj[i][j]);
			s.pop();//remove the top element from the stack/path
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
	s.push(start);//pushing the first element to the stack
	dfs(start);//dfs from the starting element
	s.pop();//remove the top element
	cout<<"Number of unique path between the given two vertices is : "<<count;
}
