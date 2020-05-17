#include<bits/stdc++.h>
#define ll long long
using namespace std;




void buildTree(ll arr[],ll *segmentTree,ll start,ll end,ll treeIndex)
{
	if(start == end)
	{
		segmentTree[treeIndex] = arr[start];
		return; 
	}
	
	ll mid = (start+end)/2;
	
	buildTree(arr,segmentTree,start,mid,treeIndex*2+1);
	buildTree(arr,segmentTree,mid+1,end,treeIndex*2+2);
	
	segmentTree[treeIndex] = segmentTree[treeIndex*2+1] +segmentTree[treeIndex*2+2];
	return;
}
ll getSum(ll *segmentTree,ll left,ll right,ll start,ll end,ll treeIndex)
{
	if(start>=left && end <=right) // full 
	{
		return segmentTree[treeIndex]; 
	}
	if(start>right || end<left) //none
	{
		return 0;
	}
	else //partial
	{
		int mid = (start+end)/2;
		return getSum(segmentTree,left,right,start,mid,2*treeIndex+1) + getSum(segmentTree,left,right,mid+1,end,2*treeIndex+2);
	}
}

void update(ll *segmentTree,ll start,ll end,ll treeIndex,ll dif,ll index)
{
	if(index<start || index>end)
		return;
	segmentTree[treeIndex] +=dif;
	if(start == end)
		return;
	else
	{
		int mid = (start+end)/2;
		update(segmentTree,start,mid,2*treeIndex+1,dif,index);
		update(segmentTree,mid+1,end,2*treeIndex+2,dif,index);
	}
}



int main()
{
	// @author -- Rahul Rai 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll t;
	cin>>t;
	ll Case = 1;
	while(Case<=t)
	{
		ll n,q;
		cin>>n>>q;
		//your code starts here : 
		ll temp[n];
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>temp[i];
		for(int i=0;i<n;i++)
		{
			arr[i] = pow(-1,i)*temp[i]*(i+1);
			temp[i] = pow(-1,i)*temp[i];
		}
			
		ll x= 2*(int)pow(2, (int)(ceil(log2(n)))) - 1;
		ll segmentTree[x];
		ll start = 0,end = n-1;
		ll treeIndex = 0;
		buildTree(arr,segmentTree,start,end,treeIndex);
			
		
		ll segmentTree1[x];
		buildTree(temp,segmentTree1,start,end,treeIndex);
		
		
		ll finalAns = 0;
		while(q--)
		{
			char ch;
			ll l,r;
			cin>>ch;
			cin>>l>>r;
			ll treeIndex = 0;
			if(ch == 'Q') // Query
			{
				l--;
				r--;
				ll temp1=0,temp2=0,ans ;
					temp1 = getSum(segmentTree,l,r,start,end,treeIndex);
					temp2 = getSum(segmentTree1,l,r,start,end,treeIndex);
					ans = temp1 - (l*(temp2));
					if(l%2==1)
					{
						ans = 0-ans;
					}
				cout<<ans<<" ";
				finalAns += ans;
			}
			else //Update
			{
				l--;
				ll index = l;
				ll data1 = pow(-1,index)*r;
				ll data = pow(-1,index)*r*(index+1);
				update(segmentTree,0,n-1,0,data-arr[index],index);
				update(segmentTree1,0,n-1,0,data1-temp[index],index);
				arr[index] = data;
				temp[index] = data1;
				
			}
		}
		
		cout<<"Case #"<<Case++<<": "<<finalAns<<endl;
	}
}
