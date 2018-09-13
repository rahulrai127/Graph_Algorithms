/*
This program is for representing a graph in Adjency List format
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	cout<<"enter number of vertices and edges : ";
	int v,e;
	cin>>v>>e;
	vector<int> adj[v];  //array of vectors to store the adjacent nodes for each node
	cout<<"enter the connections : ";
	int a,b;
	for(int i=0;i<e;i++) //creating the graph in Adjency List format
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=0;i<e;i++) //Displaying the graph created above
	{
		cout<<i+" :  ";
		for(vector<int>::iterator j = adj[i].begin();j!=adj[i].end();j++)
		{
			cout<<"-->"<<*j;
		}
		cout<<endl;
	}
	return 0;
}

