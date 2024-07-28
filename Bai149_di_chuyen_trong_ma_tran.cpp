#include<bits/stdc++.h>
using namespace std;

 
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
		int c[n+5][m+5];
		memset(c,-1,sizeof(c));
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cin>>a[i][j];
		}
		
		queue<pair<int,int>> que;
		que.push({1,1});
		c[1][1] = 0;
		while(!que.empty())
		{
			pair<int,int> ans = que.front();
			que.pop();
			int i = ans.first, j = ans.second;
			int x = a[i][j];
			if(c[i][j+x] == -1 && i >= 1 && i <= n && j+x >= 1 && j+x <= m)
			{
				que.push({i,j+x});
				c[i][j+x] = c[i][j]+1;
			}
			
			if(c[i+x][j] == -1 && i+x >= 1 && i+x <= n && j >= 1 && j <= m)
			{
				que.push({i+x,j});
				c[i+x][j] = c[i][j]+1;
			}
			
			// Th nào tiến tới trước a[n][m] trước thì số bước sẽ ít nhất.
			if(c[n][m] != -1)
				break;	
		}
		
		cout<<c[n][m]<<endl;
	}
	
	
	return 0;
}