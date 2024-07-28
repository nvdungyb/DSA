#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		set<int> st1, st2;
		int x;
		for(int i = 0; i < n; i++)
		{
			cin>>x;
			st1.insert(x);
		}
		for(int i = 0; i < m; i++)
		{
			cin>>x;
			if(st1.count(x))
				st2.insert(x);
			st1.insert(x);
		}
		
		for(auto x:st1)
			cout<<x<<" ";
		cout<<endl;
		for(auto x:st2)
			cout<<x<<" ";
		
		cout<<endl;
	}
  	
	
	return 0;
}