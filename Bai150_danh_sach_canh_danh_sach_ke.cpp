#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		int v, e;
		cin>>v>>e;
		vector<int>vt[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		
		for(int i = 1; i <= v; i++)
		{
			cout<<i<<": ";
			for(auto x:vt[i])
				cout<<x<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}