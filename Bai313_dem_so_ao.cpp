#include<bits/stdc++.h>
using namespace std;

char a[105][105];
int n, m;
pair<int,int> b[8] ={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void loang(int x, int y)
{
	a[x][y] = '.';
	for(int i = 0; i <= 7; i++)
	{
		int x_new = x+b[i].first;
		int y_new = y+b[i].second;
		if(x_new >= 1 && x_new <= n && y_new >= 1 && y_new <= m && a[x_new][y_new] == 'W')
			loang(x_new,y_new);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			cin>>a[i][j];
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == 'W'){
				loang(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;


	return 0;
}
