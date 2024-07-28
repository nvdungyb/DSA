#include<bits/stdc++.h>
using namespace std;


bool visited[505];
int a[505][505], adj[505][205], MAXN = 2005;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n >> m;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin>>a[i][j];
				if(abs(j-i) == 1 || i == j)
				{
					adj[i][j] = a[i][j];
				}else{
					adj[i][j] = MAXN;
				}
			}
		}
		
	 
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}
		
		cout<<endl;
	}


	return 0;
}
