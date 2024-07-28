#include<bits/stdc++.h>
using namespace std;

int n, m;
long long a[105], b[105], c[300];

void process(long long a[], long long b[])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			c[i+j] += b[j]*a[i];
		}
	}
	
	for(int i = 0; i < n+m-1; i++)
		cout<<c[i]<<" ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int i = 0; i < m; i++)
			cin>>b[i];
		
		memset(c, 0, sizeof(c));
		process(a,b);	
		
		cout<<endl;
	}


	return 0;
}
