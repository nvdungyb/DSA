#include<bits/stdc++.h>
using namespace std;

int n,m,a[101][101];
pair<int,int>b[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void dfs(int i,int j)
{
	a[i][j]=0;
	for(int k = 0; k <= 7; k++)
	{
		int x = i + b[k].first;
		int y = j + b[k].second;
		if(x >= 0 && x<n && y >= 0 && y<m && a[x][y])
		{
			dfs(x,y);
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<m; j++)
				cin>>a[i][j];
		}
		
		int cnt = 0;
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<m; j++)
			{
				if(a[i][j])
				{
					dfs(i,j);
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	
	return 0;
}