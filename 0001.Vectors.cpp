/*
This program is to understand basic of vectors , as we will be using it for most of our implentation of graph algorithms.
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<double> vec1; //declaring a vector
	for(int i=0;i<10;i++)
	{
		 vec1.push_back(i); //adding element at last position of vector
	}
	vec1.insert(vec1.begin()+5,2); //adding element at 5 th index of vector
	vec1.erase(vec1.begin()+6,vec1.begin()+8); //deleting element from 6th index(inclusive) to 8th index(not inclusive) in a vector
	for(vector<double>::iterator i = vec1.begin();i!=vec1.end();i++) //displaying a vector using iterator
	{
		cout<<*i<<" ";
	}
	
	cout<<'\n'<<vec1.empty();  //return true( or 1 ) if vector is empty else false( or 0 )
	return 0;
}
