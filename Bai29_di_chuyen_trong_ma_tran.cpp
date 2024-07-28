#include<bits/stdc++.h>
using namespace std;

int b[15][15];

int toHop(int n,int m)
{
	if(n == m || n == 0)
	{
		b[n][m] = 1;
		return 1;
	}
	if(b[n][m])
		return b[n][m];
	else{
		b[n][m] = toHop(n-1,m-1) + toHop(n,m-1);
		return b[n][m];	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int a[n+5][m+5];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin>>a[i][j];
		cout<<toHop(n-1,n+m-2);
		cout<<endl;
	}
	
	
	return 0;
}