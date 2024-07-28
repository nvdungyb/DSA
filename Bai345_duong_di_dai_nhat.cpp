#include<bits/stdc++.h>
using namespace std;

int a[25][25], n ,m;
int cnt, ans;

void Try(int i)
{
	for(int j = 0; j < n; j++)
	{
		if(a[i][j])
		{
			a[i][j] = 0;
			a[j][i] = 0;
			cnt++;
			ans = max(ans, cnt);
			Try(j);
			cnt--;
			a[i][j] = 1;
			a[j][i] = 1;
		}
	}
}

void longest_path()
{
	cnt = 0, ans = 0;
	for(int i = 0; i < n; i++)
	{
		Try(i);				// phải thăm từ tất cả các đỉnh, nếu lỡ tồn tại đồ thị không liên thông.
	}
	cout<<ans;
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
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			cin>>x>>y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		
		longest_path();
		
		cout<<endl;
	}


	return 0;
}
