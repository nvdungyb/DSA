#include<bits/stdc++.h>
using namespace std;

int a[505][505], n, m;
pair<int,int> b[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void loang(int x,int y)
{
	a[x][y] = 0;
	for(int i = 0; i < 8; i++)
	{
		int x_new = x+b[i].first;
		int y_new = y+b[i].second;
		if(x_new >= 0 && x_new < n && y_new >= 0 && y_new < m && a[x_new][y_new])
		{
			loang(x_new,y_new);
		}
	}
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
		{
			for(int j = 0; j < m; j++)
				cin>>a[i][j];
		}
		
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(a[i][j])
				{
					loang(i,j);
					cnt++;
				}
			}
		}
		cout<<cnt;
		cout<<endl;
	}
	
	
	return 0;
}